#!/bin/bash

continuer='1'
nb_succ='0'
nb_err='0'

while [ $continuer == "1" ]; do
    if [ $# == "2" ]; then
	chemin="$1"
	dossier="`pwd`/$2"
	poubelle="`pwd`/$2/../poubelle"
	nb_ph=`find $dossier -name \* | wc -l`
	nb_ph=$(($nb_ph-1))
    elif [ $# == "3" ]; then
	chemin="$1"
	dossier="`pwd`/$2"
	poubelle="`pwd`/$3"
	nb_ph=`find $dossier -name \* | wc -l`
	nb_ph=$(($nb_ph-1))
    else
	continuer='0'
	echo "ERREUR : le nombre de parametre est incorrecte -> $#"
    fi

    if [ $continuer == '1' ]; then
	fichier_inf="$chemin/fichier_inf"
	ttphoto=`ls $dossier`
	#echo -e "$nb_ph\n$dossier\n$poubelle\n${ttphoto[*]}\n"
	echo -e "$nb_ph\n$dossier\n$poubelle\n${ttphoto[*]}\n" > $fichier_inf
	$1/out $fichier_inf

	i=0
	while IFS= read -r ligne; do
	    if [ "$i" -eq 0 ]; then
		continuer=$ligne
	    elif [ "$i" -eq 1 ]; then
		nb_succ=$(($ligne+$nb_succ))
	    elif [ "$i" -eq 2 ]; then
		nb_err=$(($ligne+$nb_err))
	    fi
	    i=$(($i+1))
	done < $fichier_inf
    fi
done

echo -e "\n>>> total :\n\tsuccess : $nb_succ\n\terror : $nb_err"
