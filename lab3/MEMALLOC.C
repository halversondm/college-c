#include <stdio.h>
#include <stdlib.h>

double *dvecalloc(int low_d, int high_d)
{
double *d;

d = (double *)calloc((unsigned)(high_d-low_d+1),sizeof(double));
if (!d)
{
fprintf(stderr,"dvecalloc:  unable to allocate memory");
exit(1);
}
return(d-low_d);
}

float *fvecalloc(int low_f,int high_f)
{
float *f;

f=(float *)calloc((unsigned)(high_f-low_f+1),sizeof(float));
if (!f)
{
fprintf(stderr,"fvecalloc:  unable to allocate memory");
exit(1);
}
return(f-low_f);
}

int *ivecalloc(int low,int high)
{
int *i;

i=(int *)calloc((unsigned)(high-low+1),sizeof(int));
if (!i)
{
fprintf(stderr,"ivecalloc:  unable to allocate memory");
exit(1);
}
return(i-low);
}

char *cvecalloc(int low_c,int high_c)
{
char *c;

c=(char *)calloc((unsigned)(high_c-low_c+1),sizeof(char));
if (!c)
{
fprintf(stderr,"cvecalloc:  unable to allocate memory");
exit(1);
}
return(c-low_c);
}

double **dmatalloc(int rowlow_d,int rowhigh_d,int collow_d,int colhigh_d)
{
int i;
double **dm;
dm = (double **) calloc((unsigned) (rowhigh_d-rowlow_d+1), sizeof(double *));
if (!dm)
{
fprintf(stderr,"dmatalloc:  unable to allocate memory");
exit(1);
}
dm -= rowlow_d;

for (i=rowlow_d;i<=rowhigh_d;i++)
{
dm[i] = (double *) calloc((unsigned) (colhigh_d-collow_d+1), sizeof(double));
if(!dm[i])
{
fprintf(stderr,"dmatalloc:  unable to allocate memory");
exit(1);
}
dm[i] -= collow_d;
}
return (dm);
}

float **fmatalloc(int rowlow_f,int rowhigh_f,int collow_f,int colhigh_f)
{
int j;
float **fm;
fm = (float **) calloc((unsigned) (rowhigh_f-rowlow_f+1), sizeof(float *));
if (!fm)
{
fprintf(stderr,"fmatalloc:  unable to allocate memory");
exit(1);
}
fm -= rowlow_f;

for (j=rowlow_f;j<=rowhigh_f;j++)
{
fm[j] = (float *) calloc((unsigned) (colhigh_f-collow_f+1), sizeof(float));
if(!fm[j])
{
fprintf(stderr,"fmatalloc:  unable to allocate memory");
exit(1);
}
fm[j] -= collow_f;
}
return (fm);
}

int **imatalloc(int rowlow,int rowhigh,int collow,int colhigh)
{
int k;
int **im;
im = (int **) calloc((unsigned) (rowhigh-rowlow+1), sizeof(int *));
if (!im)
{
fprintf(stderr,"imatalloc:  unable to allocate memory");
exit(1);
}
im -= rowlow;

for (k=rowlow;k<=rowhigh;k++)
{
im[k] = (int *) calloc((unsigned) (colhigh-collow+1), sizeof(int));
if(!im[k])
{
fprintf(stderr,"imatalloc:  unable to allocate memory");
exit(1);
}
im[k] -= collow;
}
return (im);
}

char **cmatalloc(int rowlow_c,int rowhigh_c,int collow_c,int colhigh_c)
{
int k;
char **cm;
cm = (char **) calloc((unsigned) (rowhigh_c-rowlow_c+1), sizeof(char *));
if (!cm)
{
fprintf(stderr,"cmatalloc:  unable to allocate memory");
exit(1);
}
cm -= rowlow_c;

for (k=rowlow_c;k<=rowhigh_c;k++)
{
cm[k] = (char *) calloc((unsigned) (colhigh_c-collow_c+1), sizeof(char));
if(!cm[k])
{
fprintf(stderr,"cmatalloc:  unable to allocate memory");
exit(1);
}
cm[k] -= collow_c;
}
return (cm);
}

void free_dvector(double *v,int nl,int nh)
{
int k;
k = nl + nh - nh;
free((char*) (v+k));
}

void free_fvector(float *v,int nl,int nh)
{
int k;
k = nl + nh - nh;
free((char*) (v+k));
}

void free_ivector(int *v,int nl,int nh)
{
int k;
k = nl + nh - nh;
free((char*) (v+k));
}

void free_cvector(char *v,int nl,int nh)
{
int k;
k = nl + nh - nh;
free((char*) (v+k));
}

void free_dmatrix(double **m,int nrl,int nrh,int ncl,int nch)
{
int i,k;
k = nrl + nch - nch;

for(i=nrh;i>=nrl;i--) free((char*) (m[i]+ncl));
free((char*) (m+k));
}

void free_fmatrix(float **m,int nrl,int nrh,int ncl,int nch)
{
int i,k;
k = nrl + nch - nch;

for(i=nrh;i>=nrl;i--) free((char*) (m[i]+ncl));
free((char*) (m+k));
}

void free_imatrix(int **m,int nrl,int nrh,int ncl,int nch)
{
int i,k;
k = nrl + nch - nch;

for(i=nrh;i>=nrl;i--) free((char*) (m[i]+ncl));
free((char*) (m+k));
}

void free_cmatrix(char **m,int nrl,int nrh,int ncl,int nch)
{
int i,k;
k = nrl + nch - nch;

for(i=nrh;i>=nrl;i--) free((char*) (m[i]+ncl));
free((char*) (m+k));
}
