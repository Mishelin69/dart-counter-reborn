# 🎯 Dart Counter (ESP32-S3)

This project is a dart counter application built with [ESP-IDF](https://github.com/espressif/esp-idf) for the **ESP32-S3** microcontroller.  
It was developed and tested on **Ubuntu 24.04.2 LTS (x86_64)** using **ESP-IDF v5.5**.

---

## 📦 Requirements

Before building, make sure you have:

- [CMake](https://cmake.org/)
- [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/get-started/) (with **ESP32-S3 board support** installed)  
  👉 Follow the official Espressif installation guide for your system.

---

## ⚡ Build Instructions

1. **Clone the repository**
   ```bash
   git clone https://github.com/your-username/dart-counter.git
   cd dart-counter
   ```

2. **Activate ESP-IDF**  
   Open a terminal and activate your ESP-IDF environment:
   ```bash
   . $HOME/esp/esp-idf/export.sh
   ```

3. **Select the target**  
   (Only needs to be run once per project or after cleaning.)
   ```bash
   idf.py set-target esp32s3
   ```

4. **Optional: Configure the project**  
   If you want to tweak settings:
   ```bash
   idf.py menuconfig
   ```
   > 💡 After changing configuration, `idf.py build` will automatically regenerate files.  
   > You don’t need to re-run `set-target` unless you switch boards.

5. **Build the project**
   ```bash
   idf.py build
   ```

6. **Flash to your ESP32-S3**  
   Connect your board via USB and run:
   ```bash
   idf.py flash
   ```
   > ⚠️ Ensure the serial port is not being used by another program (e.g., a serial monitor).

7. **Monitor device output**
   ```bash
   idf.py -p YOUR_PORT monitor
   ```
   Replace `YOUR_PORT` with your device port (e.g., `/dev/ttyUSB0` on Linux).  

---

## ✅ Done!

You should now have the Dart Counter firmware running on your ESP32-S3. 🎉
