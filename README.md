<img src="https://capsule-render.vercel.app/api?type=waving&color=0:00599C,100:023e8a&height=180&section=header&text=ft_printf&fontSize=55&fontColor=fff&animation=fadeIn&fontAlignY=36" width="100%"/>

<div align="center">

[![Language](https://img.shields.io/badge/language-C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![School](https://img.shields.io/badge/42-Kocaeli-00BABC?style=for-the-badge)](https://42kocaeli.com.tr/)
[![Norm](https://img.shields.io/badge/norminette-passing-brightgreen?style=for-the-badge)](https://github.com/42School/norminette)
![Visitor](https://visitor-badge.laobi.icu/badge?page_id=Sayicon.ft_printf)

**C standart kütüphanesindeki `printf()` fonksiyonunun sıfırdan yeniden uygulaması.**

</div>

---

## Proje Hakkında

`ft_printf`, `printf(3)` fonksiyonunun 42 Kocaeli müfredatındaki yeniden yazım projesidir. Variadic fonksiyon mekanizması (`va_list`, `va_arg`, `va_end`) kullanılarak format string işleme ve tip dönüşümleri sıfırdan implemente edilmiştir.

Fonksiyon, orijinal `printf` gibi **yazdırılan karakter sayısını** döndürür.

---

## Desteklenen Format Belirteçleri

| Belirteç | Açıklama | Örnek Girdi | Çıktı |
|:--------:|----------|------------|-------|
| `%c` | Tek karakter | `'A'` | `A` |
| `%s` | String | `"hello"` | `hello` |
| `%d` | Ondalık tamsayı (int) | `42` | `42` |
| `%i` | Tamsayı | `-7` | `-7` |
| `%u` | İşaretsiz tamsayı | `4294967295` | `4294967295` |
| `%x` | Onaltılık küçük harf | `255` | `ff` |
| `%X` | Onaltılık büyük harf | `255` | `FF` |
| `%p` | Pointer adresi | `ptr` | `0x7ffd...` |
| `%%` | Yüzde işareti literal | `%%` | `%` |

---

## Kullanım

### Kütüphane Olarak Derleme

```bash
cd ft_printf
make
# libftprintf.a oluşturulur
```

### Kendi Projenize Entegrasyon

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    ft_printf("Merhaba, %s!\n", "dunya");
    ft_printf("Sayi: %d\n", 42);
    ft_printf("Hex: %x | %X\n", 255, 255);
    ft_printf("Adres: %p\n", (void *)&count);
    count = ft_printf("Bu satir %d karakter.\n", 18);
    ft_printf("Yazdirilan karakter sayisi: %d\n", count);
    return (0);
}
```

**Derleme:**
```bash
gcc -Wall -Wextra -Werror main.c ft_printf/libftprintf.a -o program
./program
```

**Çıktı:**
```
Merhaba, dunya!
Sayi: 42
Hex: ff | FF
Adres: 0x7ffd5a3b2c10
Bu satir 18 karakter.
Yazdirilan karakter sayisi: 22
```

---

## Proje Yapısı

```
ft_printf/
└── ft_printf/
    ├── ft_printf.c          # ana fonksiyon + format dispatch
    ├── ft_printf.h          # prototip bildirimleri
    ├── ft_putchar.c         # %c
    ├── ft_putstr.c          # %s
    ├── ft_putnbr.c          # %d, %i
    ├── ft_put_un_nbr.c      # %u
    ├── ft_putx_low.c        # %x
    ├── ft_putx_up.c         # %X
    ├── ft_putaddress.c      # %p
    ├── ft_hxdigit_count.c   # hex basamak sayacı
    └── Makefile
```

---

## Nasıl Çalışır?

`ft_printf` format string'i karakter karakter okur ve `%` karakterine ulaşınca ilgili yardımcı fonksiyonu çağırır:

```
ft_printf("%s has %d items at %p\n", "list", 5, ptr)
                │         │         │
                ▼         ▼         ▼
          ft_putstr()  ft_putnbr() ft_putaddress()
```

1. `%` görülene kadar karakteri doğrudan `write()` ile yaz
2. `%` görülünce sonraki belirteci oku
3. `va_arg` ile değişken argüman listesinden ilgili değeri al
4. Belirtece özel yardımcı fonksiyonu çağır
5. Her fonksiyon yazdırdığı karakter sayısını `sum` değişkenine ekler
6. `ft_printf` toplam karakter sayısını döndürür

---

## Derleme Seçenekleri

```bash
make        # libftprintf.a oluştur
make clean  # .o dosyalarını sil
make fclean # .o + .a sil
make re     # temizle ve yeniden derle
```

---

## Notlar

- `NULL` pointer için `%s` `(null)` yazar (Linux davranışı)
- `%p` adresleri `0x` öneki ile yazar
- Dönüş değeri: başarıda yazdırılan karakter sayısı, hata durumunda `-1`

---

<div align="center">

[![GitHub](https://img.shields.io/badge/GitHub-Sayicon-181717?style=for-the-badge&logo=github)](https://github.com/Sayicon)

</div>

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:023e8a,100:00599C&height=100&section=footer" width="100%"/>
