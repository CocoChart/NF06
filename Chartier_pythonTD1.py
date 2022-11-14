from datetime import date
import numpy as np
from tkinter import *

#Exercice 1
def E1q1() :
    Date = date.today()
    print("Bonjour UTT ! \n Nous sommes le",Date.day,"/", Date.month, "/", Date.year, "\n corentin.chartier@utt.fr")
def E1q2() : 
    nom = "Chartier"
    prenom = "Corentin"
    semestre = "TC03"
    age = 18
    univ = "UTT"
    prog = "python"
    print("Je m'appelle", prenom, nom, "Je suis en", semestre, "à l'", univ, "j'ai", age,"ans et mon langage favori est", prog)
def E1q3() :
    name = input("Quel est votre nom ?\n")
    print("Bonjour",name,",bienvenue en NF06!")

#Exercice 2
def E2():
    a = 3
    b = 2.6
    c = ""
    d = True
    print("a est de type", type(a),"b est de type", type(b),"c est de type", type(c),"d est de type", type(d))

    #Question 3 & 4 : C'est possible, car les variables ne sont pas typées en Python

    b_int = int(b)
    a_float = float(a)
    print ("a = ",a,"; a réel =",a_float," ; b =",b," ; b entier",b_int)

    a_str = str(a)
    b_str = str(b)
    print("\na caractere : ", a_str, "b caractere : ", b_str )

#Exercice 3
def E3q1():
    x = int(input("Donnez le premier entier x \n"))
    y = int(input("Donnez le second entier y \n"))
    Somme = x + y
    Diff = x - y
    Prod = x * y
    Div = x / y
    Quot = x // y
    Reste = x % y
    print ("x + y = ", Somme,"x - y =", Diff,"x * y = ", Prod, "x / y =", Div, "x = ",Quot,"y +",Reste )
def E3q2() :
    B = int(input("Donnez la base du triangle"))
    H = int(input("Donnez sa hauteur"))
    A = (B * H)/2
    print("Aire du triangle : ",A)
def E3q3() :
    R = int(input("Entrez le rayon du cercle"))
    H = int(input("Entrez la hauteur"))
    B = np.pi * R**2
    V = (B*H)/3
    print("L'aire de la base est : ", B,"\nLe volume du cône est : ", V)
def E3q4(a,b) :
    a, b = b, a
    print("a =", a,"b=",b)

# Exercice 4
def E4q1(chaine1):
    print("La chaîne 1 a pour longueur" ,len(chaine1))
def E4q2(chaine1, chaine2):
    print(chaine1+chaine2)
def E4q3(chaine1, chaine2):
    print(chaine1.replace("Bonjour",chaine2))
def E4q4(chaine1):
    print(chaine1.upper())
    print(chaine1.lower())
    print(chaine1.title())
def E4q5(chaine1):
    print(chaine1.split())

#Interface graphique
def Exo1():
    fenetre=Tk()
    label = Label(fenetre, text="Exercice 1")
    label.pack()
    bouton=Button(fenetre, text="Question 1", command=E1q1)
    bouton.pack()
    bouton=Button(fenetre, text="Question 2", command=E1q2)
    bouton.pack()
    bouton=Button(fenetre, text="Question 3", command=E1q3)
    bouton.pack()
    fenetre.mainloop()
def Exo3():
    fenetre=Tk()
    label = Label(fenetre, text="Exercice 3")
    label.pack()
    bouton=Button(fenetre, text="Question 1", command=E3q1)
    bouton.pack()
    bouton=Button(fenetre, text="Question 2", command=E3q2)
    bouton.pack()
    bouton=Button(fenetre, text="Question 3", command=E3q3)
    bouton.pack()
    bouton=Button(fenetre, text="Question 4", command=E3q4)
    bouton.pack()
    fenetre.mainloop()
def Exo4():
    chaine1 = input("Entrer une phrase \n")
    chaine2 = input("Entrer une deuxième phrase\n")
    fenetre=Tk()
    label = Label(fenetre, text="Exercice 4")
    label.pack()
    bouton=Button(fenetre, text="Question 1", command=lambda:E4q1(chaine1))
    bouton.pack()
    bouton=Button(fenetre, text="Question 2", command=lambda:E4q2(chaine1,chaine2))
    bouton.pack()
    bouton=Button(fenetre, text="Question 3", command=lambda:E4q3(chaine1,chaine2))
    bouton.pack()
    bouton=Button(fenetre, text="Question 4", command=lambda:E4q4(chaine1))
    bouton.pack()
    bouton=Button(fenetre, text="Question 5", command=lambda:E4q5(chaine1))
    bouton.pack()
    fenetre.mainloop()

fenetre=Tk()
label = Label(fenetre, text="Quel Exercice exécuter ?")
label.pack()
bouton=Button(fenetre, text="Exercice 1", command=Exo1)
bouton.pack()
bouton=Button(fenetre, text="Exercice 2", command=E2)
bouton.pack()
bouton=Button(fenetre, text="Exercice 3", command=Exo3)
bouton.pack()
bouton=Button(fenetre, text="Exercice 4", command=Exo4)
bouton.pack()
fenetre.mainloop()