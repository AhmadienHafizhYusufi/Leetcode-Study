## Algoritma
Kasus ini dapat dikerjakan dengan algoritma **Dutch National Flag**. Algoritma ini menggunakan tiga pointer (`low`, `mid`, dan `high`) untuk membagi array menjadi tiga bagian:
- `low` melacak posisi elemen 0 (merah).
- `mid` melacak posisi elemen yang diproses.
- `high` melacak posisi elemen 2 (biru).

## Langkah-langkah Algoritma
1. Inisialisasi `low` dan `mid` dengan 0, dan `high` dengan `n-1`.
``` c++
int low = 0, mid = 0, high = nums.size() - 1;
```
2. Looping indeks array selama `mid` kurang dari atau sama dengan `high`.
``` c++
while (mid <= high) {
	...
}
```
3. Cek elemen ke-`mid`:
   - Jika elemen ke-`mid` sama dengan 0, tukar elemen ke-`low` dengan elemen ke-`mid`, dan increment `low` dan `mid`.
``` c++
if (nums[mid] == 0) {
         swap(nums[low], nums[mid]);
         low++;
         mid++;
     }
```
   - Jika elemen ke-`mid` sama dengan 1, increment `mid`.
``` c++
else if (nums[mid] == 1) {
         mid++;
     }
```
   - Jika elemen ke-`mid` sama dengan 2, tukar elemen ke-`mid` dengan elemen ke-`high`, dan decrement `high`.
``` c++
else {
         swap(nums[mid], nums[high]);
         high--;
     }
```

## Contoh Eksekusi
Misalkan diberikan array `nums = [2,0,2,1,1,0]`.
### Inisialisasi
- `low = 0`
- `mid = 0`
- `high = 5` (indeks terakhir dari array `nums`)

### Iterasi 1 (Karena mid <= high (0 <= 5))
- `nums[mid] = 2` (elemen ke-0 sama dengan 2)
- Tukar elemen ke-`mid` dengan elemen ke-`high` ({`2`,0,2,1,1,`0`})
- Array setelah tukar: `{0, 0, 2, 1, 1, 2}`
- `high--` (high = 4)
- `mid` tetap (mid = 0)

### Iterasi 2 (Karena mid <= high (0 <= 4)))
- `nums[mid] = 0` (elemen ke-0 sama dengan 0)
- Tukar elemen ke-`low` dengan elemen ke-`mid` ({`0`,0,2,1,1,2})
- Array setelah tukar: `{0, 0, 2, 1, 1, 2}`
- `low++` (low = 1)
- `mid++` (mid = 1)

### Iterasi 3 (Karena mid <= high (1 <= 4)))
- `nums[mid] = 0` (elemen ke-1 sama dengan 0)
- Tukar elemen ke-`low` dengan elemen ke-`mid` ({0,`0`,2,1,1,2})
- Array setelah tukar: `{0, 0, 2, 1, 1, 2}`
- `low++` (low = 2)
- `mid++` (mid = 2)

### Iterasi 4 (Karena mid <= high (2 <= 4)))
- `nums[mid] = 2` (elemen ke-2 sama dengan 2)
- Tukar elemen ke-`mid` dengan elemen ke-`high` ({0,0,`2`,1,1,`2`})
- Array setelah tukar: `{0, 0, 2, 1, 1, 2}`
- `high--` (high = 3)
- `mid` tetap (mid = 2)

### Iterasi 5 (Karena mid <= high (2 <= 3)))
- `nums[mid] = 1` (elemen ke-2 sama dengan 1)
- `mid++` (mid = 3)
- Array tetap: `{0, 0, 2, 1, 1, 2}`
- `low` dan `high` tetap

### Iterasi 6 (Karena mid <= high (3 <= 3)))
- `nums[mid] = 1` (elemen ke-3 sama dengan 1)
- `mid++` (mid = 4)
- Array tetap: `{0, 0, 2, 1, 1, 2}`
- `low` dan `high` tetap

Karena mid > high (4 > 3), algoritma selesai. Array akhir: `{0, 0, 1, 1, 2, 2}`.