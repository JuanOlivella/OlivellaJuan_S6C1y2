# Compila el programa de la ecuacion del resorte

g++ -std=c++11 OlivellaJuan_cuerda.cpp 


#Ejecuta el programa de la ecuacion del resorte

./a.out > datosPlot.dat


# Genera el grafico de la ecuacion del resorte

python OlivellaJuan_plots.py

rm a.out

rm datosPlot.dat
