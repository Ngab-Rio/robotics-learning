# Robotics Learning

Repository untuk belajar **Embedded System, IoT, Robotika, dan Drone** secara bertahap menggunakan praktik langsung.

Repository ini berisi eksperimen, catatan, dan project kecil yang dibuat selama proses belajar robotika dari dasar sampai sistem yang lebih kompleks.

Platform utama yang digunakan adalah **ESP32** dengan **PlatformIO** dan **Arduino Framework**.

## Jalur Pembelajaran

```text
Embedded Basics
      ↓
GPIO
      ↓
PWM
      ↓
ADC
      ↓
Communication
 ├── UART
 ├── I2C
 └── SPI
      ↓
Sensor
      ↓
Actuator
      ↓
Feedback & Control
      ↓
PID
      ↓
Robotika
      ↓
Drone
```

## Struktur Repository

```text
robotics-learning/
│
├── 01-embedded-basic/
│   └── 01-blink/
│
├── 02-gpio/
│   └── ...
│
├── 03-pwm/
│   └── ...
│
├── 04-adc/
│   └── ...
│
├── 05-communication/
│   ├── 01-uart/
│   ├── 02-i2c/
│   └── 03-spi/
│
├── 06-sensors/
│   └── ...
│
├── 07-actuators/
│   └── ...
│
├── 08-control-systems/
│   └── ...
│
├── 09-robotics/
│   └── ...
│
├── 10-drone/
│   └── ...
│
└── projects/
    └── ...
```

Setiap eksperimen dibuat sebagai **project PlatformIO terpisah** agar dapat diuji dan dikembangkan secara independen.

## Perangkat Keras

Perangkat yang digunakan atau akan digunakan dalam proses belajar:

* ESP32
* Kabel USB
* Breadboard
* LED
* Push button
* Potensiometer
* Sensor
* Servo motor
* DC motor
* Brushless motor
* ESC
* MPU6050

Kebutuhan hardware akan ditambahkan sesuai dengan materi yang sedang dipelajari.

## Software

* VS Code
* PlatformIO
* Arduino Framework
* C++

## Materi

### 01 — Embedded Basics

| Eksperimen | Deskripsi                                    | Status  |
| ---------- | -------------------------------------------- | ------- |
| Blink      | Mengontrol LED bawaan ESP32 menggunakan GPIO | Selesai |

### 02 — GPIO

| Eksperimen   | Deskripsi                              | Status       |
| ------------ | -------------------------------------- | ------------ |
| Button       | Membaca input digital dari tombol      | Direncanakan |
| LED          | Mengontrol LED eksternal               | Direncanakan |
| Button + LED | Menggabungkan input dan output digital | Direncanakan |

### 03 — PWM

| Eksperimen | Deskripsi                        | Status       |
| ---------- | -------------------------------- | ------------ |
| Basic PWM  | Membuat sinyal PWM               | Direncanakan |
| Duty Cycle | Memahami dan mengatur duty cycle | Direncanakan |
| Frequency  | Memahami frekuensi PWM           | Direncanakan |
| Servo PWM  | Mengontrol servo menggunakan PWM | Direncanakan |

### 04 — ADC

| Eksperimen      | Deskripsi                           | Status       |
| --------------- | ----------------------------------- | ------------ |
| Analog Reading  | Membaca nilai analog                | Direncanakan |
| Potentiometer   | Membaca tegangan yang berubah       | Direncanakan |
| Voltage Reading | Mengubah nilai ADC menjadi tegangan | Direncanakan |

### 05 — Communication

| Eksperimen | Deskripsi                  | Status       |
| ---------- | -------------------------- | ------------ |
| UART       | Komunikasi serial          | Direncanakan |
| I2C        | Komunikasi menggunakan I2C | Direncanakan |
| SPI        | Komunikasi menggunakan SPI | Direncanakan |

### 06 — Sensors

| Eksperimen | Deskripsi                           | Status       |
| ---------- | ----------------------------------- | ------------ |
| Ultrasonic | Mengukur jarak                      | Direncanakan |
| MPU6050    | Membaca accelerometer dan gyroscope | Direncanakan |

### 07 — Actuators

| Eksperimen | Deskripsi                              | Status       |
| ---------- | -------------------------------------- | ------------ |
| Servo      | Mengontrol servo                       | Direncanakan |
| DC Motor   | Mengontrol motor DC                    | Direncanakan |
| ESC        | Mengontrol brushless motor melalui ESC | Direncanakan |

### 08 — Control Systems

| Eksperimen    | Deskripsi                                 | Status       |
| ------------- | ----------------------------------------- | ------------ |
| Feedback      | Memahami sistem feedback                  | Direncanakan |
| PID           | Membuat PID controller sederhana          | Direncanakan |
| MPU6050 + PID | Menggunakan feedback sensor untuk kontrol | Direncanakan |

### 09 — Robotika

Menggabungkan sensor, actuator, dan sistem kontrol menjadi sistem robot sederhana.

Contoh:

```text
Sensor
  ↓
ESP32
  ↓
Logika kontrol
  ↓
Motor
```

### 10 — Drone

Tahap lanjutan untuk memahami sistem dasar drone:

```text
IMU
 ↓
Pembacaan Sensor
 ↓
Estimasi Orientasi
 ↓
PID Controller
 ↓
Motor Output
 ↓
ESC
 ↓
Brushless Motor
```

Materi drone akan dipelajari setelah konsep embedded system, sensor, actuator, dan sistem kontrol sudah dipahami.

## Metode Belajar

Setiap materi mengikuti alur:

```text
Teori
  ↓
Eksperimen
  ↓
Implementasi
  ↓
Pengamatan
  ↓
Debugging
  ↓
Dokumentasi
```

Tujuannya bukan hanya membuat hardware bekerja, tetapi memahami **kenapa hardware tersebut bekerja**.

## Perintah PlatformIO

Build project:

```bash
pio run
```

Build dan upload ke ESP32:

```bash
pio run -t upload
```

Menjalankan serial monitor:

```bash
pio device monitor
```

## Catatan

Repository ini merupakan **lab belajar pribadi**.

Kode dibuat secara bertahap dari eksperimen sederhana menuju sistem yang lebih kompleks. Beberapa implementasi mungkin sederhana atau eksperimental karena fokus utama repository ini adalah **proses belajar dan pemahaman konsep**, bukan membuat library atau framework siap produksi.
