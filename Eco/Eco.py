from pylab import *

print "hello"


wolfes = 3.
elks = 200.

wil = 700.


a1 = []
a2 = []
a3 = []


a1.append(wolfes)
a2.append(elks)
a3.append(wil)

wolves1 = wolfes
elks1 = elks
wil1 = wil

fe = 0
fw = 0

R = range(0,100)

for i in range(1,100):

    
    wolfes = wolves1
    elks = elks1
    wil = wil1


    #fill vectors
    if(wolves1 < 1 ):
        
        wolves1 = 0
        #if i%20 == 0 : wolves = 6

    else:
        if((elks - wolfes) < 0):
               wolves1 = wolfes - wolfes/4.
           
        else: 
               wolves1 = wolfes + wolfes/4.
            
    if( elks1 < 1 ):
         
        elks1 = 0
        #if i%20 == 0 : elks1 = 10

    else:
        if (wil - elks/4.) < 0:
            if fe > 2:
                elks1 = elks - elks/10. - wolfes
            else:
                elks1 = elks - elks/2.
        else:
            elks1 = elks + elks/10. - wolfes
            
    if( wil1 < 1 ):
        fe  = fe +1
        wil1 = 1
        
    else:
        wil1  = wil + wil/10. - elks/4.
        fe = 0

        


    if(wil1 < 0):
        wil1 = 0
    if(wil1 > 3000): wil1 = 3000   
    if(elks1 < 0): elks1 = 0
    if(wolves1 < 0): wolves1 = 0
    


    a1.append(wolves1)
    a2.append(elks1)
    a3.append(wil1)



    
    print "turn :" , i
    print "wolfes :",wolves1
    print "elks   :",elks1
    print "willows:",wil1




plt.plot(R,a3,"r--",label ='willows')
plt.plot(R,a2,"b--",label = 'elks')
plt.plot(R,a1,"g--",label= 'wolves')
plt.legend(loc = 'upper right')

plt.xlabel('years')
plt.ylabel('Population')
plt.show()


close()
