from math import *
import re
from random import randrange
#Exercice 5
def Exo5():
    prenom=input("Quel est votre prénom ?\n")
    age=int(input("Quel age avez vous ?\n"))
    taille=int(input("Quel est votre taille (en cm) ?\n"))
    
    if len(prenom)>20:
        print("Le nom est long\n")
    elif len(prenom)>15:
        print("Le nom est semi-long\n")
    elif len(prenom)>7 and len(prenom)<11:
        print("Le nom est semi-court\n")
    elif len(prenom)<8:
        print("Le nom est court\n")
    
    if age>=18 :
        print("Bravo, vous êtes majeur\n")
    
    if taille > 172:
        print("Bravo, vous êtes grand\n")

#Exo5()

#Exercice 6
def est_negatif(nb):
    if nb<0: return "neg"
    else : return "pos"
def est_pair(nb):
    if nb%2 == 0 : return "pair"
    else : return "impair"
def est_premier(nb):
    prime = 1
    for i in range(2,int(sqrt(nb))+1):
        if nb % i == 0 : 
            prime = 0
            return 0
    if prime == 1 :
        return 1
def compte_pairs(liste):
    impairs=0
    pairs=0
    for i in range(len(liste)):
        even = est_pair(liste[i])
        match even:
            case "pair":
                pairs+=1
            case "impair":
                impairs+=1
    return pairs,impairs
def compte_premiers(liste):
    nbprem=0
    for i in range(len(liste)):
        prime=est_premier(liste[i])
        nbprem+=prime
    return nbprem



'''lpair,limpairs = compte_pairs([1,2,3,5,6,8])
print(lpair,limpairs)
lprem=compte_premiers([2,3,11,13,17,86,90,45])
print(lprem)'''

#Exercice 7
def password():
    pwd = input("Entre votre mot de passe : ")
    if len(re.findall("[a-z]", pwd)) < 2:
        print("Le mot de passe doit contenir au moins 2 lettres minuscules")
    elif len(re.findall("[A-Z]", pwd)) < 2:
        print("Le mot de passe doit contenir au moins 2 lettres majuscules")
    elif len(re.findall("[0-9]", pwd)) < 2:
        print("Le mot de passe doit contenir au moins 2 chiffres")
    elif len(re.findall("[$#@]", pwd)) == 0:
        print("Le mot de passe doit contenir au moins l'un de ces caractères : $ # @")
    elif len(pwd) < 6 or len(pwd) > 16:
        print("Le mot de passe doit faire entre 6 et 16 caractères")
    else:
        print("Le mot de passe est valide !")

#password()

#Exrcice 8
def equa():
    a = int(input("Entrer le coeff de x²\n"))
    b = int(input("Entrer le coeff de x\n"))
    c = int(input("Entrer la constante\n"))
    
    #discriminant
    delta = b**2 - 4*a*c
    x1="//"
    x2="//"
    if delta>0:
        x1 = (-b - sqrt(delta)) / (2*a)
        x2 = (-b + sqrt(delta)) / (2*a)
    elif delta == 0:
        x1 = (-b/(2*a))
    elif delta<0:
        r = sqrt(abs(delta))
        x1 = complex(-b/(2*a), r/(2*a))
        x2 = complex(-b/(2*a), -r/(2*a))
    print("Solutions de",a,"x² +",b,"x +",c,": \n x1 =",x1,"x2 = ", x2)
#equa()

#Exercice 9
def devinette():
    x = randrange(101)
    n=-1
    i=0
    while n!=x:
        i+=1
        print("Essai n°",i)
        n=int(input("Choisissez un nombre entre 0 et 100\n"))
        if n>x:
            print("Trop grand")
        elif n<x:
            print("Trop petit")
    print("Trouvé en ",i,"essais")

#devinette()

#Exercice 10
def fibo():
    rang=int(input("Entrer un rang"))
    Unm1=1
    Unm2=0
    for i in range(rang-2):
        Un=Unm1+Unm2
        Unm2=Unm1
        Unm1=Un
    print("U"+str(rang),"=",Unm1)

#fibo()

#Exercice 11
def binomialCoeff(n, p):
    if p==0 or p==n:
        return 1
    return binomialCoeff(n-1, p-1) + binomialCoeff(n-1, p)

print(binomialCoeff(5,2))

#Exercice 12 
def analyse(string):
    txt=string.split(" ")
    print("Nombre de mots :",len(txt))

    voy = len(re.findall("[aàeéèêëiîïoôuûy]", string))
    print("Nombre de voyelles :", voy)

    mots2v=0
    for i in range(len(txt)):
        if len(re.findall("[aàeéèêiîoôuûy]", txt[i]))>=2:
            mots2v+=1
    print("Nombre de mots à 2 voyelles ou plus :",mots2v)

#analyse("Bonjour à vous les amis")