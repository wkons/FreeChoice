//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#include "MTrand.hpp"

MTRand *rnd;

#define SZ_X 1600
#define SZ_Y 1000

char *buf;

Graphics::TBitmap *bmp;

// Получение числа Фибоначчи по его номеру

int Fib(int n)
{
  if (n<2) return n;

  int a=1, b=1, c, i;

  for (i=1;i<n;i++)
  {
    c=a+b; a=b; b=c; }

  return a;
}

// Обработка одного шага свободного выбора

// a/b - вероятность выбора единицы

// c/d - вероятность выбора нуля

int StepFib(int a,int b,int c,int d)
{
  int s=rnd->randInt()%b; // целое случайное число [0,b)

  if (s<a) return 1;

  s=rnd->randInt()%((b-a)*d);

  if (s<b*c) return 0;

  return 2;
}

// Осуществление свободного выбора

// вероятность генерации единицы равна 0.618

int FreeFib()
{
  int p=0, s;

loop:

  s=StepFib(Fib(2+p),Fib(3+p),Fib(1+p),Fib(4+p));

  if (s==2)
  {
    p+=2; goto loop; }

  return s;

}

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  // Инициализация генератора случайных чисел и графики

  rnd = new MTRand();

  bmp = new Graphics::TBitmap();

  bmp->Width=SZ_X;

  bmp->Height=SZ_Y;

  bmp->PixelFormat = pf24bit;

  DoubleBuffered=1;

  // Инициализация буфера сети

  buf=(char*)malloc(SZ_X*SZ_Y);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
  delete rnd, bmp;

  free(buf);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  double num=0;

  for (int i=0;i<SZ_X*SZ_Y;i++)
  {
	buf[i]=FreeFib();

	num+=buf[i];
  }

  char tt[100];

  sprintf(tt,"Количество единиц: %.0lf",num);

  Label1->Caption=tt;

  sprintf(tt,"Количество нулей: %.0lf",SZ_X*SZ_Y-num);

  Label2->Caption=tt;

  sprintf(tt,"Соотношение единиц и нулей: %.8lf",num/(SZ_X*SZ_Y));

  Label3->Caption=tt;

  Repaint();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormPaint(TObject *Sender)
{
  for (int i=0;i<SZ_Y;i++)
  {
	unsigned char *b=(unsigned char*)bmp->ScanLine[i];

	for (int j=0;j<SZ_X;j++)
	{
	  if (buf[i*SZ_Y+j])
	  {
		b[j*3+0]=128;
		b[j*3+1]=255;
		b[j*3+2]=128;
	  }
	  else
	  {
		b[j*3+0]=0;
		b[j*3+1]=0;
		b[j*3+2]=0;
	  }
	}
  }

  TRect r;

  r.top=PaintBox1->Top;

  r.left=PaintBox1->Left;

  r.bottom=PaintBox1->Top+PaintBox1->Height;

  r.right=PaintBox1->Left+PaintBox1->Width;

  Canvas->Pen->Color=clRed;

  Canvas->Rectangle(r.left-1,r.top-1,r.right+1,r.bottom+1);

  Canvas->StretchDraw(r,bmp);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
  Repaint();
}
//---------------------------------------------------------------------------


