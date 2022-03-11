#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct orang {
  char nama[30];
  int usia;

  struct orang *next;
} orang;

int main(int argc, char const *argv[]) {
  orang *head, *curr, *node;
  // <a> Jelaskan kegunaan 3 variabel dalam potongan kode ini
  /*  JAWABAN
      Ketiga variabel pointer ini ('head', 'curr', dan 'node') berguna sebagai
      variabel penunjuk yang penting bagi struktur data linked list kita.
      'head' sebagai titik awal (start) kita dalam menelusuri linked list yang
      kita buat.
      'curr' sebagai titik lokasi kita sekarang dalam linked list ketika
      sedang menelusuri linked list tersebut.
      'node' sebagai *template* atau struktur basis member/node dalam
      linked list kita ketika ingin menambahkan node dalam list tersebut.
  */

  char nama[30];
  int usia, exit = 1;
  char lanjut;

  head = curr = NULL;

  while (exit == 1) {
    system("cls");
    printf("Data diri yang akan dimasukkan dalam linked list\n");
    printf("------------------------------------------------\n\n");
    printf("Masukkan nama: "); scanf("%[^\n]", &nama);
    printf("Masukkan usia: "); scanf("%i", &usia);
    getchar();

    node = (struct orang *)malloc(sizeof(struct orang));
    // <b> Apa kegunaan baris kode berikut?
    /*JAWABAN
      Baris tersebut bisa digunakan sebagai perintah untuk mengalokasikan
      ruang pada memori sebesar ukuran dari tipe data 'struct orang` lalu
      jadikan ruang memori tersebut sebagai pointer untuk `struct orang`
      tersebut.
    */

    node->next = NULL;

    strcpy(node->nama, nama);
    node->usia = usia;

    if (head == NULL) {
    //<c> Apa kegunaan baris kode berikut?
    /*JAWABAN
      Jika node 'head' kosong (belum ada data), maka node 'node' yang akan
      mengisi posisi 'head' dan menjadi kepala dari linked listnya.
    */
        head = node;
    }
    else {
    //<d> Apa kegunaan baris kode berikut? Apa yang membedakannya dengan <c>?
    /*JAWABAN
      Jika head memiliki data didalamnya, maka node 'curr' akan terisi oleh data
      yang ada didalam node 'head'. Setelah itu akan dilakukan looping untuk
      mencari node yang tidak memiliki data didalam pointer nextnya. Lalu setelah
      ditemukan node tersebut, kita isi pointer next pada node 'curr' dengan data 'node'.
    */
        curr = head;
      while (curr->next != NULL) {
        curr = curr->next;
      }
      curr->next = node;
    }

    //<e> Apa tujuan dari looping ini (pilih)?
    // b. Error handling sederhana.
    do {
      printf("Lanjut (y/n)?: ");
      scanf("%c", &lanjut);
      getchar();
      if (lanjut == 'y' || lanjut == 'Y') {
        exit = 1;
        break;
      } else if (lanjut == 'n' || lanjut == 'N') {
        exit = 0;
        break;
      } else {
        printf("Masukkan input yang benar !\n");
        printf("Tekan tombol apapun untuk melanjutkan. . .\n");
      }
    } while (1);
  }

  system("cls");
  printf("Daftar nama yang terdapat dalam linked list\n");
  printf("-------------------------------------------\n\n");

  curr = head;

  while (curr != NULL) {
  //<f> Apa yang dilakukan dalam pengulangan berikut?
  /*JAWABAN
    'while' loop dibawah akan mengoutput nama dan usia yang ada di dalam node
    'curr', lalu akan pergi ke node lainnya yang ada di next pada 'curr' tersebut.
  */
    printf("Nama: %s\nUsia: %d\n", curr->nama, curr->usia);
    printf("-------------------------\n");
    curr = curr->next;
  }
  while (head != NULL) {
    //<g> Tuliskan perintah untuk melakukan free memory dari head.
    // Gunakan contoh potongan kode pada Free sebagai petunjuk
    orang *temp = head;
    head = temp->next;
    temp->next = NULL;
    free(temp);
  }
  return 0;
}
