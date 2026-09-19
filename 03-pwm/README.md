# 03 — PWM

PWM (Pulse Width Modulation) digunakan untuk mengatur output dengan mengubah **duty cycle** dari sinyal digital secara periodik.

Pada ESP32, PWM dapat digunakan untuk berbagai kebutuhan seperti:

* mengatur brightness LED
* membuat efek fade
* merespons input tombol
* mengubah nilai PWM berdasarkan input potentiometer
* mengontrol actuator seperti servo

---

## Konsep Dasar

Sinyal PWM memiliki beberapa parameter utama:

```text
Frequency
    ↓
berapa kali sinyal berulang per detik

Duty Cycle
    ↓
berapa persen waktu sinyal berada pada HIGH

Resolution
    ↓
berapa banyak tingkat nilai duty yang tersedia
```

Contoh duty cycle:

```text
100%  → HIGH terus
75%   → HIGH 75% dari periode
50%   → HIGH 50% dari periode
25%   → HIGH 25% dari periode
0%    → LOW terus
```

Untuk resolution 8-bit:

```text
2^8 = 256 nilai

0 ─────────────────── 255
```

Sehingga:

```text
0   → 0%
64  → ≈25%
128 → ≈50%
192 → ≈75%
255 → 100%
```

---

## Struktur Eksperimen

```text
03-pwm/
├── 01-led-pwm-fade/
├── 02-pwm-button/
├── 03-pwm-potensiometer/
└── 04-pwm-servo/
```

---

# 01 — LED PWM Fade

**Directory:**

```text
01-led-pwm-fade/
```

### Tujuan

Memahami dasar PWM dengan mengubah duty cycle LED secara bertahap.

Duty cycle dinaikkan:

```text
0 → 255
```

kemudian diturunkan:

```text
255 → 0
```

Sehingga LED terlihat melakukan efek fade:

```text
mati
 ↓
redup
 ↓
terang
 ↓
redup
 ↓
mati
```

### Konsep yang dipelajari

* PWM frequency
* PWM resolution
* duty cycle
* LEDC pada ESP32
* `ledcSetup()`
* `ledcAttachPin()`
* `ledcWrite()`
* penggunaan `for` untuk mengubah duty cycle

### Alur

```text
Program
   ↓
ubah duty cycle
   ↓
LEDC PWM
   ↓
LED
   ↓
brightness berubah
```

---

# 02 — PWM + Button

**Directory:**

```text
02-pwm-button/
```

### Tujuan

Menggabungkan GPIO input dengan PWM.

Button digunakan untuk mengubah brightness LED.

Contoh:

```text
Button dilepas
      ↓
PWM 25%
      ↓
LED redup
```

dan:

```text
Button ditekan
      ↓
PWM 100%
      ↓
LED terang
```

### Konsep yang dipelajari

* GPIO input
* `INPUT_PULLUP`
* `digitalRead()`
* PWM
* kondisi `if`
* integrasi input dan output

Pada konfigurasi `INPUT_PULLUP`:

```text
Button dilepas → HIGH
Button ditekan → LOW
```

---

# 03 — Potentiometer → PWM

**Directory:**

```text
03-pwm-potensiometer/
```

### Tujuan

Menggunakan potentiometer sebagai input analog untuk mengatur brightness LED menggunakan PWM.

Alurnya:

```text
Potentiometer
      ↓
ADC
      ↓
analogRead()
      ↓
0–4095
      ↓
map()
      ↓
0–255
      ↓
PWM
      ↓
LED
```

Pada ESP32 dengan ADC 12-bit:

```text
ADC:

0 ───────────────────── 4095
```

Sedangkan PWM menggunakan resolution 8-bit:

```text
PWM:

0 ─────────────── 255
```

Karena kedua range berbeda, nilai ADC perlu dipetakan menggunakan `map()`.

Contoh:

```text
ADC 0     → PWM 0
ADC 1024  → PWM ≈64
ADC 2048  → PWM ≈128
ADC 3072  → PWM ≈192
ADC 4095  → PWM 255
```

### Konsep yang dipelajari

* ADC sebagai input
* `analogRead()`
* mapping nilai
* `map()`
* PWM
* hubungan input analog dengan output PWM

---

# 04 — Potentiometer → Servo

**Directory:**

```text
04-pwm-servo/
```

### Tujuan

Memahami bahwa PWM tidak hanya digunakan untuk brightness LED.

Pada servo, sinyal PWM digunakan sebagai **sinyal kontrol posisi**.

Alurnya:

```text
Potentiometer
      ↓
ADC
      ↓
0–4095
      ↓
map()
      ↓
0–180°
      ↓
Servo
```

Contoh:

```text
Pot kiri
   ↓
≈ 0°

Pot tengah
   ↓
≈ 90°

Pot kanan
   ↓
≈ 180°
```

Berbeda dengan LED, nilai hasil `map()` di sini merepresentasikan **posisi servo**, bukan duty cycle LED secara langsung.

### Konsep yang dipelajari

* ADC
* potentiometer
* mapping
* servo control
* hubungan input analog dengan posisi actuator
* perbedaan penggunaan PWM untuk LED dan servo

---

# PWM API pada ESP32

Pada environment ESP32 yang digunakan dalam project ini, Arduino-ESP32 menggunakan API LEDC:

```cpp
ledcSetup(channel, frequency, resolution);
ledcAttachPin(pin, channel);
ledcWrite(channel, duty);
```

Contoh:

```cpp
#define LED_PIN 2

#define PWM_FREQ 5000
#define PWM_RESOLUTION 8
#define PWM_CHANNEL 0

void setup() {
    pinMode(LED_PIN, OUTPUT);

    ledcSetup(
        PWM_CHANNEL,
        PWM_FREQ,
        PWM_RESOLUTION
    );

    ledcAttachPin(
        LED_PIN,
        PWM_CHANNEL
    );
}
```

Kemudian duty cycle dapat diubah:

```cpp
ledcWrite(PWM_CHANNEL, 128);
```

Nilai `128` dengan resolution 8-bit menghasilkan duty cycle sekitar 50%.

---

# `analogWrite()`

Arduino juga menyediakan API yang lebih sederhana:

```cpp
analogWrite(pin, value);
```

Contoh:

```cpp
analogWrite(LED_PIN, 128);
```

Untuk eksperimen dasar, `analogWrite()` lebih sederhana.

Namun pada pembelajaran ESP32, LEDC digunakan terlebih dahulu agar konsep berikut dapat dipahami secara eksplisit:

```text
Channel
Frequency
Resolution
Duty Cycle
```

---

# PWM vs GPIO Digital

GPIO digital biasa hanya memiliki dua kondisi:

```text
LOW
HIGH
```

PWM tetap menggunakan sinyal digital:

```text
HIGH
LOW
HIGH
LOW
HIGH
LOW
```

tetapi durasi HIGH dan LOW diatur.

Contoh 50% duty cycle:

```text
HIGH ────
LOW  ────
HIGH ────
LOW  ────
```

Contoh 25%:

```text
HIGH ──
LOW  ───────
HIGH ──
LOW  ───────
```

Perbedaan durasi tersebut dapat digunakan untuk mengontrol berbagai output.

---

# Hubungan dengan Sistem Robotik

PWM merupakan konsep penting karena nantinya digunakan pada berbagai actuator.

Contoh:

```text
PWM
 │
 ├── LED
 │
 ├── Servo
 │
 ├── Motor DC
 │
 └── ESC
```

Namun masing-masing actuator memiliki karakteristik sinyal dan kebutuhan kontrol yang berbeda.

Karena itu, memahami PWM pada LED terlebih dahulu menjadi dasar sebelum masuk ke actuator yang lebih kompleks.

---

# Hasil Pembelajaran

Setelah menyelesaikan module ini, konsep yang diharapkan sudah dipahami:

* [x] PWM
* [x] Frequency
* [x] Duty cycle
* [x] PWM resolution
* [x] LEDC ESP32
* [x] `ledcSetup()`
* [x] `ledcAttachPin()`
* [x] `ledcWrite()`
* [x] `analogWrite()`
* [x] ADC sebagai input PWM
* [x] `analogRead()`
* [x] `map()`
* [x] Potentiometer → PWM
* [x] Potentiometer → Servo
* [x] PWM sebagai dasar kontrol actuator

---

# Next

Setelah PWM selesai, pembelajaran dilanjutkan ke:

```text
04 — ADC
```

Fokusnya bukan lagi bagaimana ADC digunakan untuk mengontrol PWM, tetapi bagaimana **ADC bekerja sebagai sistem pembacaan input analog**.

Konsep utama:

```text
Tegangan Analog
      ↓
     ADC
      ↓
Nilai Digital
```

Kemudian akan dilanjutkan ke pembacaan tegangan, range ADC, filtering, dan penerapannya pada
