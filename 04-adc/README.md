# 04 - ADC

Materi ini membahas **Analog-to-Digital Converter (ADC)** pada ESP32.

ADC digunakan untuk membaca tegangan analog dari sensor atau komponen seperti potentiometer, kemudian mengubahnya menjadi nilai digital yang dapat diproses oleh program.

## Materi

```text
04-adc/
├── 01-analog-read-and-voltage/
└── 02-adc-filtering-sampling-rate-and-sampling-count/
```

### 01 - Analog Read and Voltage

Mempelajari dasar penggunaan ADC:

* membaca nilai analog dengan `analogRead()`
* memahami rentang ADC ESP32
* memahami resolusi ADC
* mengubah nilai ADC menjadi tegangan
* menghitung persentase dari nilai ADC

Konsep dasar:

```text
Tegangan analog
      ↓
   ADC ESP32
      ↓
   0 - 4095
      ↓
 Nilai digital
```

Perhitungan tegangan sederhana:

```cpp
voltage = adcValue * 3.3 / 4095.0;
```

ESP32 menggunakan ADC 12-bit pada konfigurasi yang digunakan dalam latihan ini:

```text
2^12 = 4096 level

Nilai ADC:
0 ──────────────── 4095
```

---

### 02 - ADC Filtering, Sampling Rate and Sampling Count

Mempelajari bagaimana data ADC dapat diambil beberapa kali dan diproses untuk mendapatkan nilai yang lebih stabil.

Materi yang dipelajari:

* sampling ADC
* jumlah sample
* averaging
* filtering sederhana menggunakan moving average
* waktu sampling
* sampling rate
* trade-off antara stabilitas dan response time

Konsep dasar:

```text
Sensor / Potentiometer
          ↓
       ADC Read
          ↓
    Multiple Samples
          ↓
        Average
          ↓
   Filtered ADC Value
```

Contoh:

```text
Sample 1 → 2040
Sample 2 → 2045
Sample 3 → 2038
Sample 4 → 2042
Sample 5 → 2041

Average → 2041.2
```

Semakin banyak sample yang digunakan, hasil rata-rata cenderung lebih stabil, tetapi waktu yang dibutuhkan untuk mendapatkan satu hasil juga semakin besar.

```text
Sample sedikit
    ↓
response lebih cepat
    ↓
filtering lebih lemah


Sample banyak
    ↓
filtering lebih kuat
    ↓
response lebih lambat
```

## Konsep Penting

### ADC Resolution

Resolusi menentukan jumlah nilai digital yang dapat dihasilkan ADC.

Untuk ADC 12-bit:

```text
2^12 = 4096 level
```

Sehingga rentangnya:

```text
0 - 4095
```

### Voltage Conversion

Nilai ADC dapat dikonversi menjadi perkiraan tegangan:

```text
ADC → Voltage

voltage = ADC × 3.3 / 4095
```

### Sampling

Sampling adalah proses mengambil nilai sensor pada waktu tertentu.

Contoh:

```text
Sensor
  ↓
Sample 1
Sample 2
Sample 3
Sample 4
...
Sample N
```

### Sampling Count

Sampling count adalah jumlah sample yang digunakan dalam satu proses pengambilan data.

Contoh:

```text
sampleCount = 5
sampleCount = 10
sampleCount = 50
sampleCount = 100
```

### Sampling Rate

Sampling rate menunjukkan berapa banyak sample yang dapat diambil dalam satu detik.

Satuannya adalah **Hertz (Hz)**.

```text
sampling rate = jumlah sample / waktu sampling
```

Contoh:

```text
100 sample
dalam 0.1 detik

sampling rate = 100 / 0.1
              = 1000 Hz
```

## Hardware

Untuk percobaan dapat menggunakan:

* ESP32 Dev Module
* Potentiometer
* Kabel jumper
* Breadboard

Potentiometer:

```text
       Potentiometer
       ┌───────────┐
3.3V ──┤           │
       │    OUT ───┼──→ ESP32 ADC
GND  ──┤           │
       └───────────┘
```

Pin ADC yang digunakan pada latihan:

```cpp
#define POT_PIN 34
```

## Platform

Project menggunakan:

* ESP32
* Arduino Framework
* PlatformIO

Konfigurasi dasar:

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
```

## Tujuan Pembelajaran

Setelah menyelesaikan materi ini, diharapkan sudah memahami:

* cara kerja dasar ADC
* cara membaca nilai analog menggunakan ESP32
* hubungan ADC dengan tegangan
* konsep resolusi ADC
* konsep sampling
* konsep filtering sederhana
* pengaruh jumlah sample terhadap response
* cara menghitung sampling rate

Materi ini menjadi dasar sebelum masuk ke **UART, I2C, dan SPI**, kemudian dilanjutkan ke pembacaan sensor seperti **MPU6050**.
