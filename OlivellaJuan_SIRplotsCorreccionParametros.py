import numpy as np
import matplotlib.pylab as plt

datos1=np.genfromtxt("datosSIR1.dat")

datos2=np.genfromtxt("datosSIR2.dat")

x1 = datos1[:,0]

y1 = datos1[:,1]

maxi1 = datos1[-1,2]

maxt1 = datos1[-1,3]

print("El numero maximo de infectados en SIR1 fue:", maxi1, ", en el dia:", maxt1)
print("")

x2 = datos2[:,0]

y2 = datos2[:,1]

maxi2 = datos2[-1,2]

maxt2 = datos2[-1,3]

print("El numero maximo de infectados en SIR2 fue:", maxi2, ", en el dia:", maxt2)

plt.figure()

plt.subplot(2,2,1)
plt.plot(y1,x1)
plt.title("SIR1")
plt.xlabel("$t(s)$")
plt.ylabel("$I(t)$")


plt.subplot(2,2,2)
plt.plot(y2,x2)
plt.title("SIR2")
plt.xlabel("$t(s)$")
plt.ylabel("$I(t)$")


plt.savefig("SIR.pdf")

