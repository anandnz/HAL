/*
   \file FireFlyDriver.h

 */

#ifndef _FIREFLY_H_
#define _FIREFLY_H_

#include <dc1394/dc1394.h>
#include <mvl/camera/camera.h>
#include "RPG/Devices/Camera/CameraDriverInterface.h"

class FireFlyDriver : public CameraDriver
{
    public:
        FireFlyDriver();
        virtual ~FireFlyDriver();
        bool Capture( std::vector<rpg::ImageWrapper>& vImages );
        bool Init();
	private:
		void _cleanup_and_exit( dc1394camera_t *pCam );
    private:
        dc1394camera_t*          m_pCam;
        dc1394_t*                m_pBus;
        dc1394video_mode_t       m_nVideoMode;
        dc1394framerate_t        m_nFramerate;
        dc1394featureset_t       m_vFeatures;
        unsigned int             m_nImageWidth;
        unsigned int             m_nImageHeight;
        mvl_camera_t*			 m_pCamMod;

};

#endif