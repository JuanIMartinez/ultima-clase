import numpy as np
import matplotlib.pylab as plt

cuerda_1=np.genfromtxt("Amplitud0.dat")
cuerda_2=np.genfromtxt("Amplitud15.dat")
cuerda_3=np.genfromtxt("Amplitud100.dat")




plt.figure()
plt.subplot(3,1,1)
plt.title('Amplitud vs tiempo')
plt.plot(cuerda_1,c="lightsalmon",label = "cuerda_0", linewidth=0.7)
plt.ylabel("Amplitud")
plt.grid()
plt.legend()
plt.subplot(3,1,2)
plt.plot(cuerda_2,c="c",label = "t=15", linewidth=0.7)
plt.ylabel("Amplitud")
plt.grid()
plt.legend()
plt.subplot(3,1,3)
plt.plot(cuerda_3,c="c",label = "t=100", linewidth=0.7)
plt.ylabel("Amplitud")
plt.xlabel("Tiempo")
plt.grid()
plt.legend()
plt.savefig("Cuerda_t.pdf")
plt.close()


