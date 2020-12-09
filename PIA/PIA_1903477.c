/******************************************************************************

Welcome to GDB Online
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
  
#define MAXLONG_BUFFER 1024
  
typedef struct alumno
{
  
char matricula[8];
   
int calif[7];
   
unsigned int NparcialesR;
   
double promedio;
 
} alumno;

 
typedef struct califprom
{
  
unsigned int NalumnosR;
   
int *califAlumnosParcial;
   
double promedio;
 
} califprom;

 
typedef struct grupo
{
  
unsigned int NalumnosR;
   
int *califAlumnos;
   
double promedio;
 
} grupo;

 
unsigned int
get_total_lines_file (const char *_filename)
{
  
FILE * stream = fopen (_filename, "r");
  
if (!stream)
    {
      
printf ("Error. Hubo un problema al abrir el archivo %s.\n",
	       _filename);
      
exit (EXIT_FAILURE);
    
}
  
unsigned int n_lines = 0;
  
char texto[MAXLONG_BUFFER];
  
while (fgets (texto, MAXLONG_BUFFER, stream) != NULL)
    {
      
n_lines++;
    
}
  
 
fclose (stream);
  
 
return n_lines;

}


 
char **
split_str (char *str, const char a_delim)
{
  
char **_str = NULL;
  
size_t count;
  
char *str_tmp = str;
  
char *last_delim = NULL;
  
char delim[2];
  
delim[0] = a_delim;
  
delim[1] = '\0';
  
 
while (*str_tmp)
    {
      
if (*str_tmp == a_delim)
	{
	  
count++;
	  
last_delim = str_tmp;
	
}
      
str_tmp++;
    
}
  
 
count += last_delim < (str + strlen (str) - 1);
  
 
count++;
  
 
_str = malloc (sizeof (char *) * (size_t) count);
  
if (_str)
    {
      
size_t idx = 0;
      
char *token = strtok (str, delim);
      
while (token)
	{
	  
assert (idx < count);
	  
*(_str + idx++) = strdup (token);
	  
token = strtok (NULL, delim);
	
}
      
 
assert (idx == (count - 1));
      
*(_str + idx) = '\0';
    
}
  else
    {
      
printf ("Error. No se pudo reservar espacio en memoria.\n");
      
exit (EXIT_FAILURE);
    
}
  
 
return _str;

}


 
alumno register_student (char **tokens)
{
  
size_t i = 0, k = 0;
  
alumno a;
  
 
for (i = 0; *(tokens + i); ++i)
    {
      
if (i > 0)
	{
	  
a.calif[k] = (int) strtol (tokens[i], NULL, 10);
	  
k++;
	
}
      else
	{
	  
strncpy (a.matricula, tokens[i], strlen (tokens[i]));
	
}
    
}
  
 
return a;

}


 
void
cargararchivo (const char *_filename, alumno * alumnos)
{
  
FILE * stream = fopen (_filename, "r");
  
if (!stream)
    {
      
printf ("Error. Hubo un problema al abrir el archivo %s.\n",
	       _filename);
      
exit (EXIT_FAILURE);
    
}
  
size_t idx = 0;
  
size_t i = 0;
  
char texto[MAXLONG_BUFFER];
  
unsigned int n_lines = 0;
  
char **tokens = NULL;
  
while (fgets (texto, MAXLONG_BUFFER, stream) != NULL)
    {
      
n_lines++;
      
texto[strcspn (texto, "\n")] = '\0';
      
if (n_lines > 1)
	{
	  
tokens = split_str (texto, ',');
	  
if (tokens)
	    {
	      
alumnos[idx] = register_student (tokens);
	      
 
for (i = 0; *(tokens + i); ++i)
		{
		  
free (*(tokens + i));
		
}
	      
free (tokens);
	      
tokens = NULL;
	    
}
	  
idx++;
	
}
    
}
  
 
fclose (stream);

}


 
void
guardarenarchivo (const char *_namefile, alumno * alumnos,
		  califprom * calificaciones, grupo g, const size_t tamA,
		  const size_t tamC)
{
  
FILE * stream = fopen (_namefile, "w");
  
if (!stream)
    {
      
printf ("Error. No se pudo abrir el archivo %s.\n", _namefile);
      
exit (EXIT_FAILURE);
    
}
  
size_t i = 0, j = 0;
  
size_t len = 0;
  
fprintf (stream,
	    "Matricula ; Parcial 1 ; Parcial 2 ; Parcial 3 ; Parcial 4 ; Parcial 5 ; Parcial 6 ; Parcial 7 ; Promedio Calif Parciales ; Numero de Parciales no Aprobados ; \n");
  
for (i = 0; i < tamA; ++i)
    {
      
fprintf (stream, "`");
      
len = strlen (alumnos[i].matricula);
      
for (j = len - 4; j < len; ++j)
	{
	  
fputc (alumnos[i].matricula[j], stream);
	
}
      
fprintf (stream, "´");
      
fprintf (stream, "; %d ; %d ; %d ; %d ; %d ; %d ; %d ; %d ; %d\n",
		alumnos[i].calif[0], alumnos[i].calif[1], alumnos[i].calif[2],
		alumnos[i].calif[3], alumnos[i].calif[4], alumnos[i].calif[5],
		alumnos[i].calif[6], (int) alumnos[i].promedio,
		alumnos[i].NparcialesR);
    
} 
fprintf (stream, "Promedio ; ");
  
for (i = 0; i < tamC; ++i)
    {
      
fprintf (stream, "%d ; ", (int) calificaciones[i].promedio);
    
} 
fprintf (stream, "%d ; \n", (int) g.promedio);
  
fprintf (stream, "No Aprobados ; ");
  
for (i = 0; i < tamC; ++i)
    {
      
fprintf (stream, "%u ; ", calificaciones[i].NalumnosR);
    
}
  
fprintf (stream, "%u ; ", g.NalumnosR);
  
fclose (stream);

}


 
double
calcular_promedioFinal (int *calif, const size_t tam)
{
  
double prom = 0.0;
  
size_t i = 0;
  
for (i = 0; i < tam; ++i)
    {
      
prom += calif[i];
    
}
  
prom /= tam;
  
return prom;

}


 
unsigned int
Nparciales_Reprobados (int *calif, const size_t tam)
{
  
size_t i = 0;
  
unsigned int reprobados = 0;
  
for (i = 0; i < tam; ++i)
    {
      
if (calif[i] < 7)
	
reprobados++;
    
}
  
 
return reprobados;

}


 
void
ini_CalifParcial (unsigned *n_alumR, double *prom, int **califAlumP,
		  const size_t tam, alumno * alumnos, const unsigned idx_P)
{
  
*n_alumR = 0;
  
*prom = 0.0;
  
*califAlumP = (int *) malloc (sizeof (int) * (size_t) tam);
  
if (!(*califAlumP))
    {
      
printf ("Error. No se pudo reservar espacio en memoria\n");
      
exit (EXIT_FAILURE);
    
}
  
size_t k = 0;
  
for (k; k < tam; ++k)
    {
      
(*califAlumP)[k] = alumnos[k].calif[idx_P];
    
}

}


 
double
calcular_promParcial (int *califAlumnosP, const size_t tam)
{
  
double prom = 0.0;
  
size_t i = 0;
  
for (i; i < tam; ++i)
    {
      
prom += califAlumnosP[i];
    
}
  
prom /= tam;
  
 
return prom;

}


 
unsigned int
NalumnosReprobados_P (int *califAlumnosP, const size_t tam)
{
  
unsigned int reprobados = 0;
  
size_t i = 0;
  
for (i; i < tam; ++i)
    {
      
if (califAlumnosP[i] < 7)
	
reprobados++;
    
}
  
 
return reprobados;

}


 
void
ini_califGrupo (grupo * g, alumno * alumnos, const size_t tam)
{
  
g->califAlumnos = (int *) malloc (sizeof (int) * (size_t) tam);
  
if (!g->califAlumnos)
    {
      
printf ("Error. No se pudo reservar espacion en memoria\n");
      
exit (EXIT_FAILURE);
    
}
  
size_t i = 0;
  
for (i; i < tam; ++i)
    {
      
g->califAlumnos[i] = (int) alumnos[i].promedio;

} 
} 
 
double

calcular_promGrupo (int *califAlumnos, const size_t tam)
{
  
size_t i = 0;
  
double prom = 0.0;
  
for (i; i < tam; ++i)
    {
      
prom += califAlumnos[i];
    
}
  
prom /= tam;
  
 
return prom;

}


 
unsigned int
NAlumnosReprobados_G (int *califAlumnos, const size_t tam)
{
  
unsigned int reprobados = 0;
  
size_t i = 0;
  
for (i; i < tam; ++i)
    {
      
if (califAlumnos[i] < 7)
	
reprobados++;
    
}
  
 
return reprobados;

}


 
void
print_arrayAlumnos (alumno * alumnos, const size_t tam)
{
  
size_t i = 0, j = 0;
  
for (i = 0; i < tam; ++i)
    {
      
printf ("Alumno %d\nMatricula: %s\nCalif: ", i + 1,
	       alumnos[i].matricula);
      
for (j = 0; j < 7; ++j)
	{
	  
printf ("-%d- ", alumnos[i].calif[j]);
	
}
      
printf ("\nNumero de parciales reprobados: %u\nPromedio final: %.2lf",
	       alumnos[i].NparcialesR, alumnos[i].promedio);
      
if (i < tam - 1)
	
printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
}
  
printf ("\n");

}


 
void
print_arrayCalifP (califprom * calificaciones, const size_t tam)
{
  
size_t i = 0;
  
for (i = 0; i < tam; ++i)
    {
      
printf
	("Parcial %d\nNumero de alumnos reprobados: %u\nPromedio general del parcial: %.2lf",
	 i + 1, calificaciones[i].NalumnosR, calificaciones[i].promedio);
      
if (i < tam - 1)
	
printf ("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
}
  
printf ("\n");

}


 
int
main ()
{
  
const size_t TAM = get_total_lines_file ("calificaciones_pia_pe.csv") - 1;
  
alumno alumnos[TAM];
  
califprom calificacionesP[7];
  
grupo g =
  {
  0, NULL, 0.0};
  
size_t i = 0, j = 0;
  
 
cargararchivo ("calificaciones_pia_pe.csv", alumnos);
  
 
for (i = 0; i < TAM; ++i)
    {
      
alumnos[i].promedio =
	round (calcular_promedioFinal (alumnos[i].calif, 7));
      
alumnos[i].NparcialesR = Nparciales_Reprobados (alumnos[i].calif, 7);
    
}
  
 
for (i = 0; i < 7; ++i)
    {
      
ini_CalifParcial (&calificacionesP[i].NalumnosR,
			 &calificacionesP[i].promedio,
			 &calificacionesP[i].califAlumnosParcial, TAM,
			 alumnos, i);
      
calificacionesP[i].promedio =
	round (calcular_promParcial
	       (calificacionesP[i].califAlumnosParcial, TAM));
      
calificacionesP[i].NalumnosR =
	Nparciales_Reprobados (calificacionesP[i].califAlumnosParcial, TAM);
    
}
  
 
ini_califGrupo (&g, alumnos, TAM);
  
g.promedio = round (calcular_promGrupo (g.califAlumnos, TAM));
  
g.NalumnosR = NAlumnosReprobados_G (g.califAlumnos, TAM);
  
 
guardarenarchivo ("calificaciones_acomodadas.csv", alumnos,
		       calificacionesP, g, TAM, 7);
  
 
print_arrayAlumnos (alumnos, TAM);
  
printf ("\n");
  
print_arrayCalifP (calificacionesP, 7);
  
printf
    ("\nEl promedio del grupo es: %.2lf\nEl total de alumnos reprobados del grupo es: %u\n",
     g.promedio, g.NalumnosR);
  
 
for (i = 0; i < 7; ++i)
    {
      
free (calificacionesP[i].califAlumnosParcial);
    
}
  
free (g.califAlumnos);
  
 
return 0;

}
