# 01 - Blink

Eksperimen pertama pada pembelajaran embedded system menggunakan ESP32 dan PlatformIO.

Eksperimen ini bertujuan memahami dasar program embedded: bagaimana ESP32 menjalankan program dan mengontrol output digital melalui GPIO.

## Tujuan

Setelah menyelesaikan eksperimen ini, diharapkan memahami:

* Struktur dasar program Arduino
* Fungsi `setup()` dan `loop()`
* Konsep GPIO sebagai digital output
* Fungsi `pinMode()`
* Fungsi `digitalWrite()`
* Konsep `HIGH` dan `LOW`
* Penggunaan `delay()`
* Proses compile, upload, dan eksekusi program pada ESP32

## Hardware

* ESP32 Dev Module
* LED onboard ESP32

## Software

* PlatformIO
* Arduino Framework
* VS Code

## Konsep Dasar

Program embedded berbeda dengan program biasa karena program yang dibuat akan berinteraksi langsung dengan hardware.

Pada eksperimen ini, ESP32 digunakan untuk mengontrol LED melalui salah satu GPIO.

Alur sederhananya:

```text
Program
   ↓
ESP32
   ↓
GPIO
   ↓
LED
```

GPIO digunakan sebagai output untuk memberikan kondisi:

```text
HIGH → LED ON
LOW  → LED OFF
```

Pada ESP32, level logika digital umumnya menggunakan:

```text
HIGH ≈ 3.3V
LOW  ≈ 0V
```

## Struktur Program

Program Arduino memiliki dua fungsi utama:

```cpp
void setup() {
    // dijalankan satu kali
}

void loop() {
    // dijalankan berulang-ulang
}
```

### `setup()`

`setup()` dijalankan satu kali ketika ESP32 mulai menjalankan program.

Pada eksperimen ini digunakan untuk menentukan GPIO sebagai output.

### `loop()`

`loop()` dijalankan berulang-ulang selama ESP32 menyala.

Pada eksperimen ini digunakan untuk mengubah kondisi LED:

```text
ON
 ↓
tunggu
 ↓
OFF
 ↓
tunggu
 ↓
ON
 ↓
...
```

## Eksperimen

LED dibuat berkedip dengan interval tertentu.

Contoh:

```cpp
digitalWrite(LED_PIN, HIGH);
delay(1000);

digitalWrite(LED_PIN, LOW);
delay(1000);
```

`delay()` menggunakan satuan milidetik.

```text
1000 ms = 1 detik
500 ms  = 0.5 detik
100 ms  = 0.1 detik
```

Semakin besar nilai `delay()`, semakin lambat kedipan LED.

Semakin kecil nilai `delay()`, semakin cepat kedipan LED.

## Menjalankan Program

Build project:

```bash
pio run
```

Upload ke ESP32:

```bash
pio run -t upload
```

## Hasil

ESP32 berhasil menjalankan program dan LED berkedip secara periodik.

Eksperimen ini menjadi dasar untuk memahami hubungan:

```text
Software
   ↓
Microcontroller
   ↓
GPIO
   ↓
Hardware
```

## Catatan

`delay()` bersifat blocking. Selama `delay()` berjalan, program berhenti menunggu sebelum melanjutkan instruksi berikutnya.

Konsep ini masih cukup untuk eksperimen sederhana seperti Blink. Pada sistem yang lebih kompleks, pendekatan non-blocking akan diperlukan agar ESP32 tetap dapat melakukan beberapa pekerjaan secara responsif.

Konsep tersebut akan dipelajari pada materi berikutnya.
