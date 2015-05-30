# Zadaca6
## Zadatak
Kreirati bazu podataka u C++-u za videoteku u koja ima 4 osnovne tabele:
- Korisnici
- Film
- Žanr
- Glumci (Starring cast)

Omogućiti najbržu pretragu korisnika, filmova i glumaca. Korisnik treba da ima mogućnost podizanja novog filma, vraćanja filma te pretragu filmova po žanrovima i glumcima. Baza podataka treba da vodi čitavu historiju dizanja i vraćanja filmova kao i broj dana koliko je određeni film bio kod određenog korisnika.

Baza podataka treba u pozadini da ima implementiranu strukturu za čuvanje podataka tako organizovanu da baza na navedene zahtjeve odgovori u najbržem vremenskom intervalu.

## Implementacija baze podataka
Nakon analize problema baza podataka treba da izgleda kao što je to prikazano na sljedećoj slici.
<a href='http://postimage.org/' target='_blank'><img src='http://s21.postimg.org/688t5ynk7/Baza_Podataka_Movies.png' border='0' alt="Baza Podataka Movies" /></a><br /><br />
Vidimo da su zbog zahtjeva sve tabele povezane vezama m:n što znači da smo između tabela morali dodati nove tabele koje će voditi računa o povezivanju i historiji podizanja filmova. Svaka kolona tabele čiji je romb označen plavom bojom znači da je ta kolona neophodna pri dodavanju novog sloga u bazu podataka, ukoliko je označen bijelom bojom, znači da je neobavezno. Ključ označava identifikacioni broj odnosno indeks tabele, te je potrebno primjetiti da međutabele imaju dva identifikaciona broja.








