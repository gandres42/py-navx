# py-navx
Fork of https://github.com/strykeforce/py-navx with added functions to allow raw sensor access

## Preparing the Environment
Install prerequisite software:
```
sudo apt install git cmake python3-dev
```

## Installation
Download and install the latest version of `py-navx`:
```
git clone --recurse-submodules https://github.com/gandres42/py-navx
cd py-navx
pip install .
```

## Example

On Linux, the serial port to the navX should be `/dev/ttyACM0`.

```python
from py_navx import AHRS, SerialDataType

ahrs = AHRS("/dev/ttyACM0", SerialDataType.kProcessedData)
timestamp = ahrs.get_last_sensor_timestamp()

print("timestamp = {}".format(timestamp))
```

## License

The MIT license.

Original navX source code is Copyright (c) 2015 Kauai Labs, Inc. and is under the MIT license.
