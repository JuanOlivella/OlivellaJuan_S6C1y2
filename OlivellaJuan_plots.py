import numpy as np
import matplotlib.pylab as plt

datos1=np.genfromtxt("datosPlot.dat")

x1 = datos1[0:99,0]

y1 = datos1[0:99,1]

x2 = datos1[100:198,0]

y2 = datos1[100:198,1]

plt.figure()
plt.plot(x1,y1)
plt.title("Funcion U(t,x) en el tiempo t = 0 s")
plt.xlabel("$posicion$")
plt.ylabel("$U(t,x)$")
plt.savefig("Funcion U en cero.pdf")


plt.figure()
plt.plot(x2,y2)
plt.title("Funcion U(t,x) en el tiempo final")
plt.xlabel("$posicion$")
plt.ylabel("$U(t,x)$")
plt.savefig("Funcion U en final.pdf")


