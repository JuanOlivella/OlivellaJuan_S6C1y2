import numpy as np
import matplotlib.pylab as plt

datos1=np.genfromtxt("datosSIR1.dat")

datos2=np.genfromtxt("datosSIR2.dat")

x1 = datos1[:,0]

y1 = datos1[:,1]

x2 = datos2[:,0]

y2 = datos2[:,1]

plt.figure()

plt.subplot(2,2,1)
plt.plot(x1,y1)
plt.title("SIR1")
plt.xlabel("$t(s)$")
plt.ylabel("$I(t)$")


plt.subplot(2,2,2)
plt.plot(x2,y2)
plt.title("SIR2")
plt.xlabel("$t(s)$")
plt.ylabel("$I(t)$")


plt.savefig("SIR.pdf")

