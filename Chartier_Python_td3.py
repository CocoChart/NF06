#Exercice 13
def liste_nombre():
    liste=[]
    taille=int(input("Entrez la taille de la liste : "))
    for i in range(taille):
        liste.append(int(input("Entrez un nombre : ")))
    return liste

def calculs(liste):
    taille=len(liste)
    somme_liste=sum(liste)

    print("La somme des éléments de la liste est : ",somme_liste)
    print("La moyenne des éléments de la liste est : ",somme_liste/taille)
    produit_liste=1
    for i in range(taille):
        produit_liste*=liste[i]

    print("Le produit des éléments de la liste est : ",produit_liste)

def recherche(liste):
    cherche=int(input("Entrez un nombre à chercher dans la liste : "))
    if cherche in liste:
        print("Le nombre ",cherche," est dans la liste")

def insertion(liste):
    taille=len(liste)
    insere=int(input("Entrez un nombre à insérer dans la liste : "))
    liste.insert(int(taille/2),insere)
    return liste

def suppression(liste):
    suppr=int(input("Entrez un nombre à supprimer dans la liste : "))
    liste.remove(suppr)
    return liste

def tranche(liste):
    debut=int(input("Entrez le début de la tranche : "))
    fin=int(input("Entrez la fin de la tranche : "))
    print("La tranche est : ",liste[debut-1:fin])

#tests des fonctions
'''
liste=liste_nombre()
calculs(liste)
recherche(liste)
liste_insert=insertion(liste)
print("La liste après insertion est : ",liste_insert)
liste_suppr=suppression(liste)
print("La liste après suppression est : ",liste_suppr)
tranche(liste)
'''

#Exercice 14 : hobbies database
def hobbies():
    nombre=int(input("Entrez le nombre de personnes : "))
    usersList=[]
    for i in range(nombre):
        name=input("Entrez le nom de la personne : ")
        nbhobbies=int(input("Entrez le nombre d'hobbies de la personne : "))
        hobbiesList=[]
        for j in range(nbhobbies):
            hobbiesList.append(input("Entrez un hobby : "))
        usersList.append((name,hobbiesList))
    return usersList


def same_hobby(userslist):
    hobby=input("Entrez un hobby : ")
    count=0
    for i in range(len(userslist)):
        if hobby in userslist[i][1]:
            count+=1
    print("Il y a ",count," personnes qui ont le même hobby")

def common_hobby(userslist):
    user1=input("Entrez le nom de la première personne : ")
    user2=input("Entrez le nom de la deuxième personne : ")
    for i in range(len(userslist)):
        if user1==userslist[i][0]:
            ind1=i
        if user2==userslist[i][0]:
            ind2=i
        count=0
    for j in range(len(userslist[ind1][1])):
        if userslist[ind1][1][j] in userslist[ind2][1]:
            count+=1
    print("Ils ont",count,"hobbies en commun")

def del_hobby(userslist):
    user=input("Entrer le nom de la personne concernée : ")
    for i in range(len(userslist)):
        if user==userslist[i][0]:
            ind=i
    hobby=input("Entrer le hobby à supprimer : ")
    if hobby in userslist[ind][1]:
        userslist[ind][1].remove(hobby)
    return userslist

def del_user(userslist):
    user=input("Entrer le nom de la personne à supprimer : ")
    for i in range(len(userslist)):
        if user==userslist[i][0]:
            ind=i
    userslist.remove(userslist[ind])
    return userslist

def replace_hobby(userslist):
    user=input("Entrer le nom de la personne concernée : ")
    for i in range(len(userslist)):
        if user==userslist[i][0]:
            ind=i
    hobby=input("Entrer le hobby à supprimer : ")
    new=input("Entrer le nouveau hobby : ")
    for i in range(len(userslist)-1):
        if hobby==userslist[ind][1][i]:
            userslist[ind][1][i]=new
    
    return userslist

#tests des fonctions
'''userdb=hobbies()
print(userdb)
same_hobby(userdb)
common_hobby(userdb)
deleted_hobby=del_hobby(userdb)
print(deleted_hobby)
deleted_user=del_user(userdb)
print(deleted_user)
replaced = replace_hobby(userdb)
print(replaced)'''

#Exercice 15

def creer_etu():
    dico_C={"demonstration" : 0, "code" : 0, "presentation" : 0, "documentation" : 0}
    dico_C["demonstration"]=float(input("Entrer la note de démonstration en C : "))
    dico_C["code"]=float(input("Entrer la note de code en C : "))
    dico_C["presentation"]=float(input("Entrer la note de présentation en C : "))
    dico_C["documentation"]=float(input("Entrer la note de documentation en C : "))
    
    dico_py={"demonstration" : 0, "code" : 0, "presentation" : 0, "documentation" : 0}
    dico_py["demonstration"]=float(input("Entrer la note de démonstration en python : "))
    dico_py["code"]=float(input("Entrer la note de code en python : "))
    dico_py["presentation"]=float(input("Entrer la note de présentation en python : "))
    dico_py["documentation"]=float(input("Entrer la note de documentation en python : "))

    etu=(dico_C,dico_py)
    return etu

def moy(etuList):
    moyList=[]
    moyC=0
    moyPy=0
    for i in range(len(etuList)):
        moyC= (etuList[i][0]["demonstration"] + etuList[i][0]["code"] + etuList[i][0]["presentation"] + etuList[i][0]["documentation"]) /4
        moyPy= (etuList[i][1]["demonstration"] + etuList[i][1]["code"] + etuList[i][1]["presentation"] + etuList[i][1]["documentation"]) /4
        moyList.append((moyC,moyPy))
    return moyList

def moygen(etuList) :
    moylist=moy(etuList)
    moyC=0
    moyPy=0
    for i in range(len(moylist)):
        moyC+=moylist[i][0]
        moyPy+=moylist[i][1]
    moyC/=len(moylist)
    moyPy/=len(moylist)
    return (moyC,moyPy)

def ponderer(moygen):
    #On inverse les pondérations (par exemple si la moyenne en C est de 8/20 et en python de 12/20, on multiplie python par 40% et C par 60%, et les moyennes sont alors égales)
    tauxC=moygen[0]/(moygen[0]+moygen[1])
    tauxPy=moygen[1]/(moygen[0]+moygen[1])
    pondC,pondPy=tauxPy,tauxC
    print("Il faut pondérer le projet C par",pondC,"et le projet Python par",pondPy)
    moyC=moygen[0]*pondC 
    moyPy=moygen[1]*pondPy 
    print(moyC,moyPy)


'''liste_etu=[({'demonstration': 1.0, 'code': 2.0, 'presentation': 12.0, 'documentation': 10.0}, {'demonstration': 7.0, 'code': 6.0, 'presentation': 7.0, 'documentation': 15.0}), ({'demonstration': 13.0, 'code': 13.0, 'presentation': 14.0, 'documentation': 15.0}, {'demonstration': 16.0, 'code': 20.0, 'presentation': 19.0, 'documentation': 19.0})]'''

'''liste_etu=[]
for i in range(10):
    etu = creer_etu()
    liste_etu.append(etu)
print(liste_etu)
liste_moyenne=moy(liste_etu)
print(liste_moyenne)
generale=moygen(liste_etu)
print(generale)
ponderer(generale)'''

#Exercice 16

def ajoutfilm(liste):
    film={"titre" : "", "annee" : -1, "note" : -1, "copies" : -1, "prix" : -1 , "duree" : -1 }
    film["titre"]=input("Entrer le titre : ")
    film["annee"]=int(input("Entrer l'année : "))
    film["note"]=int(input("Entrer la note sur 10 : "))
    film["copies"]=int(input("Entrer le nombre de copies : "))
    film["prix"]=int(input("Entrer le prix : "))
    film["duree"]=int(input("Entrer la duree : "))
    liste.append(film)

def createlist(taille):
    liste=[]
    for i in range(taille):
        ajoutfilm(liste)
    return(liste)

def afficherfilms(liste, only_available):
    for i in range(len(liste)):
        if only_available and liste[i]["copies"]>0:
            print(liste[i])
        elif only_available==False:
            print(liste[i])

def trier(movieList):
    print(sorted(movieList,key=lambda film: film["note"],reverse=True))

def louer(movielist,movie):
    for i in range(len(movielist)):
        if movie==movielist[i]["titre"] and movielist[i]["titre"]>0:
            movielist[i]["copies"]+=-1
        else : print("Ce film n'est pas en stock")

'''movieList=createlist(3)
movieList=[{'titre': '1', 'annee': 1, 'note': 1, 'copies': 0, 'prix': 1, 'duree': 1}, {'titre': '2', 'annee': 2, 'note': 2, 'copies': 2, 'prix': 2, 'duree': 2}, {'titre': '3', 'annee': 3, 'note': 3, 'copies': 3, 'prix': 3, 'duree': 3}]
print(movieList)
afficherfilms(movieList,True)
louer(movieList,'2')
print(movieList)
trier(movieList)'''