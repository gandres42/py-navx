#include <string>
#include <pybind11/pybind11.h>
#include <AHRS.h>

namespace py = pybind11;

PYBIND11_MODULE(py_navx, m) {

    m.doc() = "Python bindings for Kauai Labs navX";

    py::enum_<AHRS::SerialDataType>(m, "SerialDataType")
        // Define your enum values here
        .value("kProcessedData", AHRS::SerialDataType::kProcessedData)
        .value("kRaw", AHRS::SerialDataType::kRawData);

    py::class_<AHRS>(m, "AHRS")
        .def(py::init<std::string, AHRS::SerialDataType, int>())
        .def("get_pitch", &AHRS::GetPitch)
        .def("get_roll", &AHRS::GetRoll)
        .def("get_yaw", &AHRS::GetYaw)
        .def("get_compass_heading", &AHRS::GetCompassHeading)
        .def("zero_yaw", &AHRS::ZeroYaw)
        .def("is_calibrating", &AHRS::IsCalibrating)
        .def("is_connected", &AHRS::IsConnected)
        .def("get_byte_count", &AHRS::GetByteCount)
        .def("get_update_count", &AHRS::GetUpdateCount)
        .def("get_last_sensor_timestamp", &AHRS::GetLastSensorTimestamp)
        .def("get_world_linear_accel_x", &AHRS::GetWorldLinearAccelX)
        .def("get_world_linear_accel_y", &AHRS::GetWorldLinearAccelY)
        .def("get_world_linear_accel_z", &AHRS::GetWorldLinearAccelZ)
        .def("is_moving", &AHRS::IsMoving)
        .def("is_rotating", &AHRS::IsRotating)
        .def("get_angle", &AHRS::GetAngle)
        .def("get_rate", &AHRS::GetRate)
        .def("get_actual_update_rate", &AHRS::GetActualUpdateRate)
        .def("get_requested_update_rate", &AHRS::GetRequestedUpdateRate)
        .def("get_raw_accel_x", &AHRS::GetRawAccelX)
        .def("get_raw_accel_y", &AHRS::GetRawAccelY)
        .def("get_raw_accel_z", &AHRS::GetRawAccelZ)
        .def("get_raw_gyro_x", &AHRS::GetRawGyroX)
        .def("get_raw_gyro_y", &AHRS::GetRawGyroY)
        .def("get_raw_gyro_z", &AHRS::GetRawGyroZ)
        .def("get_raw_mag_x", &AHRS::GetRawMagX)
        .def("get_raw_mag_y", &AHRS::GetRawMagY)
        .def("get_raw_mag_z", &AHRS::GetRawMagZ)
        .def("close", &AHRS::Close);


#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
