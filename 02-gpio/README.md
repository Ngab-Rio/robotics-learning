# 02 — GPIO

Materi ini membahas dasar **GPIO (General Purpose Input/Output)** pada ESP32 menggunakan Arduino Framework.

GPIO merupakan interface digital yang digunakan untuk membaca input dari perangkat seperti button dan mengontrol output seperti LED.

## Tujuan Pembelajaran

Setelah menyelesaikan materi ini, diharapkan dapat memahami:

* Konsep GPIO input dan output
* `INPUT`, `OUTPUT`, dan `INPUT_PULLUP`
* Membaca input menggunakan `digitalRead()`
* Mengontrol output menggunakan `digitalWrite()`
* Membuat event sederhana menggunakan perubahan state
* Memahami debounce pada button
* Menggunakan beberapa GPIO sekaligus
* Membedakan logical state dengan physical GPIO state

## Struktur Materi

```text
02-gpio/
├── README.md
├── 01-button/
├── 02-button-led/
├── 03-button-toggle/
├── 04-button-debounce/
├── 05-input-pulldown/
└── 06-multiple-gpio/
```

## 01 — Button

Membaca kondisi button menggunakan GPIO input.

Konsep:

```text
Button
   ↓
GPIO
   ↓
digitalRead()
   ↓
HIGH / LOW
```

Menggunakan:

```cpp
pinMode(BUTTON_PIN, INPUT_PULLUP);
```

Dengan konfigurasi pull-up:

```text
Button tidak ditekan → HIGH
Button ditekan       → LOW
```

Konsep yang dipelajari:

* GPIO sebagai input
* `pinMode()`
* `digitalRead()`
* `INPUT_PULLUP`
* `HIGH` dan `LOW`

---

## 02 — Button + LED

Menggunakan button sebagai input untuk mengontrol LED sebagai output.

```text
Button
   ↓
GPIO Input
   ↓
Program Logic
   ↓
GPIO Output
   ↓
LED
```

Konsep:

```cpp
digitalRead()
digitalWrite()
```

Contoh logika:

```text
Button ditekan → LED ON
Button dilepas → LED OFF
```

Konsep yang dipelajari:

* GPIO input
* GPIO output
* Digital input → program logic → digital output
* `digitalRead()`
* `digitalWrite()`

---

## 03 — Button Toggle

Membuat LED berubah state setiap kali button ditekan.

Berbeda dengan eksperimen sebelumnya:

```text
Button ditekan → LED ON
Button dilepas → LED OFF
```

Pada toggle:

```text
Tekan 1 → LED ON
Tekan 2 → LED OFF
Tekan 3 → LED ON
Tekan 4 → LED OFF
```

Digunakan state:

```cpp
bool ledState;
int lastButtonState;
```

Deteksi perubahan state:

```text
HIGH → LOW
```

digunakan sebagai indikasi button baru saja ditekan.

Konsep yang dipelajari:

* State
* Previous state
* Event detection
* Boolean state
* Toggle logic

---

## 04 — Button Debounce

Button mekanis tidak selalu menghasilkan satu perubahan `HIGH → LOW` yang bersih ketika ditekan.

Perubahan dapat terjadi sangat cepat:

```text
HIGH
 LOW
 HIGH
 LOW
 HIGH
 LOW
```

sebelum akhirnya stabil pada:

```text
LOW
```

Peristiwa tersebut disebut **button bounce**.

Solusinya adalah debounce.

Pada eksperimen ini digunakan:

```cpp
millis();
```

untuk mengukur berapa lama state telah bertahan.

Konsep waktu:

```text
State berubah
     ↓
Catat waktu
     ↓
Tunggu beberapa milidetik
     ↓
Periksa state
     ↓
State masih sama?
     ↓
Anggap valid
```

State yang digunakan:

```cpp
int buttonState;
int lastButtonState;
int stableButtonState;
unsigned long previousTime;
```

Konsep yang dipelajari:

* Mechanical bounce
* Debounce
* `millis()`
* Elapsed time
* Raw state
* Stable state
* Event detection setelah state stabil

---

## 05 — INPUT_PULLDOWN

Eksperimen ini digunakan untuk memahami konsep **pull-down** sebagai kebalikan dari pull-up.

Konsep dasarnya:

### Pull-up

```text
Default → HIGH
Aktif   → LOW
```

### Pull-down

```text
Default → LOW
Aktif   → HIGH
```

Tujuan pull-up dan pull-down sama:

> Memberikan kondisi default yang jelas pada GPIO agar tidak floating.

Eksperimen ESP32 untuk bagian ini sementara dilewati karena keterbatasan simulator.

Konsep akan divalidasi kembali menggunakan ESP32 ketika simulator tersedia.

---

## 06 — Multiple GPIO

Menggunakan beberapa GPIO sebagai input dan output secara bersamaan.

Contoh:

```text
Button 1 → GPIO 4
Button 2 → GPIO 16

LED 1    ← GPIO 5
LED 2    ← GPIO 17
```

Alur:

```text
Button 1 → GPIO 4  → LED 1 → GPIO 5
Button 2 → GPIO 16 → LED 2 → GPIO 17
```

Konsep yang dipelajari:

* Multiple GPIO input
* Multiple GPIO output
* Penggunaan beberapa `digitalRead()`
* Penggunaan beberapa `digitalWrite()`
* Pemisahan pin menggunakan konstanta
* GPIO sebagai interface digital umum

Contoh konfigurasi:

```cpp
#define BUTTON_PIN_1 4
#define BUTTON_PIN_2 16

#define LED_PIN_1 5
#define LED_PIN_2 17
```

## Konsep Utama

Secara umum, GPIO dapat dipahami sebagai:

```text
                 ESP32
                   │
          ┌────────┴────────┐
          │                 │
        INPUT             OUTPUT
          │                 │
      digitalRead()    digitalWrite()
          │                 │
       Button              LED
```

Input digunakan untuk **membaca kondisi dunia luar**.

Output digunakan untuk **memberikan kontrol ke perangkat lain**.

## API yang Digunakan

| API                | Fungsi                                 |
| ------------------ | -------------------------------------- |
| `pinMode()`        | Mengatur mode GPIO                     |
| `digitalRead()`    | Membaca GPIO digital                   |
| `digitalWrite()`   | Mengatur output GPIO                   |
| `millis()`         | Mengambil waktu sejak program berjalan |
| `Serial.begin()`   | Memulai komunikasi serial              |
| `Serial.print()`   | Menampilkan data ke Serial Monitor     |
| `Serial.println()` | Menampilkan data dengan newline        |

## Kesimpulan

Setelah menyelesaikan materi ini, alur dasar GPIO yang dipahami adalah:

```text
INPUT
  ↓
digitalRead()
  ↓
Program Logic
  ↓
digitalWrite()
  ↓
OUTPUT
```

Kemudian ditambahkan konsep:

```text
State
  ↓
Event Detection
  ↓
Debounce
  ↓
Multiple GPIO
```

GPIO merupakan fondasi penting sebelum masuk ke materi berikutnya karena banyak perangkat embedded dan robot pada akhirnya berinteraksi dengan hardware melalui input dan output.

## Next

Materi berikutnya:

```text
03 — PWM
```

Fokus utama:

```text
GPIO Digital
     ↓
PWM
     ↓
Mengatur duty cycle
     ↓
Kontrol intensitas LED
     ↓
Kontrol servo / motor
```
