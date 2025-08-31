# Date sınıfı

Aşağıda ismi `Date` olan bir sınıfın tanımlandığı başlık dosyası yer almaktadır. 
Bu ödevde `Date` sınıfının kodlarını yazmanız isteniyor.
`Date` sınıfı türünden bir nesnenin değeri bir tarihtir. Örnek: `15 Şubat 1998` <br>
Aşağıdaki açıklamalar kodda bulunan yorum satırlarına ilişkindir:

1. Sınıfın hizmet verdiği en küçük yıl değeri (`1900` değerini kullanabilirsiniz.)
2. `random_date` fonksiyonunun üretebileceği en eski tarihin yıl değeri.
3. `random_date` fonksiyonunun üreyebileceği en yeni tarihin yıl değeri.
4.  Haftanın günü için `enum class` türü.
5.  _Default constructor_ : `Date` nesnesini `01-01-year_base` tarihi ile oluşturmalı.
6. `Date` nesnesini gün, ay, yıl değerleri ile oluşturacak `constructor`.
7. `Date` nesnesini formatlanmış  yazıdan alacağı tarih değeri ile oluşturacak `cosntructor`. Format: `gg/aa/yil`
8. `Date` nesnesini `"calender time"` değerinden dönüştüreceği tarih değeri ile oluşturacak `constructor`.
9. Ayın günü değerini döndürmeli.
10. Ay değerini döndürmeli. `(Ocak 1, Şubat 2, ...)`
11. Tarihin yıl değerini döndürmeli.
12. Yılın günü değerini döndürmli `(01 Ocak ---> 1   31 Aralık---> 365 ya da 366`
13. Haftanın günü değerini döndürmeli.
14. Tarihin ayın günü değerini değiştirmeli.
15. Tarihin ayını değiştirmeli.
16. Tarihin yılını değiştirmeli.
17. Tarihi değiştirmeli.
18. Tarihten gün çıkartan `const` üye operatör fonksiyonu. Geri dönüş değeri elde edilen tarih olmalı.
19. Tarihi gelen gün kadar arttıran üye operatör fonksiyonu. Geri dönüş değeri `*this` olmalı.
20. Tarihi gelen gün kadar eksilten üye operatör fonksiyonu. Geri dönüş değeri `*this` olmalı.
21. Önek `++` operatörünü yükleyen fonksiyon. (Fonksiyonun referans döndürdüğüne dikkat ediniz). 
22. Sonek `++` operatörünü yükleyen fonksiyon. (Fonksiyonun referans döndürmediğine dikkat ediniz). 
23. Önek `--` operatörünü yükleyen fonksiyon. (Fonksiyonun referans döndürdüğüne dikkat ediniz). 
24. Sonek `--` operatörünü yükleyen fonksiyon. (Fonksiyonun referans döndürmediğine dikkat ediniz). 
25. Rastgele bir tarih döndüren sınıfın `static` üye fonksiyonu.
26. Artık yıl testi yapan sınıfın `static` üye fonksiyonu.
27. `Date` nesnelerinin karşılaştırılmasını sağlayacak global operatör fonksiyonları.
28. İki tarih arasındaki gün farkını döndüren global operatör fonksiyonu.
29. Gelen tarihten `n` gün sonrasını döndüren global operatör fonksiyonları.
30. İçsel `(nested) enum class Weekday` için arttırma ve eksiltme fonksiyonları.
31. Date nesnelerinin değerlerini bir çıkış akımına _(output stream)_ yazdıracak global operatör fonksiyonu `(inserter)`.
Formatlama şöyle olmalı:  `31 Ekim 2019 Persembe`.
32. `Date` nesnelerine bir giriş akımından _(input stream)_ aldığı karakterlerden oluşturulacak değeri yerleştiren global operatör fonksiyonu `(extractor)`
Formatlama: `gg/aa/yyyy` (ayıraç olarak istenilen bir karakter kullanılabilir).
33.Haftanın gününü hesaplamak için _Sakamuto_ algoritmasını kullanabilirsiniz.

### Diğer notlar:
* Dilediğiniz global fonksiyonları `"friend"` yapabilirsiniz.
* Sınıfın `private` arayüzünü dilediğiniz gibi oluşturabilirsiniz.
* Gerekli görürseniz sınıfın `public` arayüzüne eklemeler yapabilirsiniz.
* Gerekli görürseniz sınıfın `public` arayüzünde değişiklikler yapabilirsiniz.
* Sınıfın `public` öğelerinin isimlerini istediğiniz şekilde değiştirebilirsiniz.
* Dilediğiniz fonksiyonları `"constexpr"` yapabilirsiniz.
* Bu ödevde `"exception handling"` araçlarını kullanmayacağız. (`exception handling` konusunu gördükten sonra kodlarda değişiklik yapacağız.) Fonksiyonlara gönderilen argümanların uygun ve doğru değerler olduğunu varsayabilirsiniz.
* İsimlendirmeye dikkat etmelisiniz.
* Tutarlı ve kararlı bir `"indentation style"` kullanmalısınız. 
* Kod tekrarından mümkün olduğu kadar kaçınmalısınız.
* `const` doğruluğuna `(const correctness)` çok dikkat etmelisiniz. `(const olması gereken tüm varlıklar const olmalı)`
* Gereksiz yorum satırlarından mümkün olduğu kadar kaçınmalısınız.
* Yazdığınız kodların doğru çalışıp çalışmadığını sınamak için test kodları yazmalısınız.
* Derleyicinizin uygun bir `switch`'ini kullanarak mantıksal uyarı iletilerinin hata `(error)` olarak değerlendirilmesini sağlayınız.
* Gerekli olduğunu düşündüğünüz yerlerde `[[nodiscard]] attribute`'unu kullanmalısınız.
* Ay ve gün isimleri için birer _constexpr_ _lookup table_ kullanabilirsiniz.
* Şubat ayının _28_ ya da _29_ güne sahip olmasından kaynaklanacak olan kod tekrarından kaçınmak için _2_ boyutlu bir diziyi bir _lookup table_ olarak kullanabilirsiniz.


```
#ifndef DATE_H
#define DATE_H

#include <iosfwd>
#include <ctime>

namespace project {
	class Date {
	public:
		static constexpr int year_base = 1900;  //1
		static constexpr int random_min_year = 1940;  //2
		static constexpr int random_max_year = 2020;  //3
		enum class Weekday { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday }; //4
		Date(); //5 
		Date(int d, int m, int y);  //6
		explicit Date(const char* p);  //7
		explicit Date(std::time_t timer); //8
		[[nodiscard]] int get_month_day()const; //9
		[[nodiscard]] int get_month()const; //10
		[[nodiscard]] int get_year()const; //11
		[[nodiscard]] int get_year_day()const; //12
		[[nodiscard]] Weekday get_week_day()const; //13

		Date& set_month_day(int day); //14
		Date& set_month(int month); //15
		Date& set_year(int year); //16
		Date& set(int day, int mon, int year); //17
		[[nodiscard]] Date operator-(int day)const; //18
		Date& operator+=(int day); //19
		Date& operator-=(int day); //20
		Date& operator++(); //21
		Date operator++(int); //22
		Date& operator--(); //23
		Date operator--(int); //24

		friend bool operator<(const Date&, const Date&); //27
		friend bool operator==(const Date&, const Date&); //27
		[[nodiscard]] static Date random_date(); //25
		static constexpr bool isleap(int y); //26

		friend std::ostream& operator<<(std::ostream& os, const Date& date); //31
		friend std::istream& operator>>(std::istream& is, Date& date); //32
	};

	[[nodiscard]] bool operator<=(const Date&, const Date&); //27
	[[nodiscard]] bool operator>(const Date&, const Date&); //27
	[[nodiscard]] bool operator>=(const Date&, const Date&); //27
	[[nodiscard]] bool operator!=(const Date&, const Date&); //27

	[[nodiscard]] int operator-(const Date& d1, const Date& d2); //28
	[[nodiscard]] Date operator+(const Date& date, int n); //29
	[[nodiscard]] Date operator+(int n, const Date&); //29
	Date::Weekday& operator++(Date::Weekday& r); //30
	Date::Weekday operator++(Date::Weekday& r, int); //30
	Date::Weekday& operator--(Date::Weekday& r); //30
	Date::Weekday operator--(Date::Weekday& r, int); //30}
};

#endif

```