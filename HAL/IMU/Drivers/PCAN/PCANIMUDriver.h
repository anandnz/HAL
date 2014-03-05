#pragma once

#include <thread>

#include <HAL/IMU/IMUDriverInterface.h>

#include <HAL/Encoder/Drivers/PCAN/PCANListener.h>
class PCANListener;
namespace hal {

class PCANIMUDriver : public IMUDriverInterface
{
public:
    PCANIMUDriver(unsigned long int baudrate, const std::string& sCom);
    ~PCANIMUDriver();
    void RegisterIMUDataCallback(IMUDriverDataCallback Callback);

private:
    PCANListener&           m_PCANListener;
};

} /* namespace */
