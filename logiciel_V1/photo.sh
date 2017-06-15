#!/bin/bash

continuer='1'

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
    app="$chemin/c_files/app"
    ttphoto=`ls $dossier`
    #echo -e "$nb_ph\n$dossier\n$poubelle\n${ttphoto[*]}\n"
    echo -e "$nb_ph\n$dossier\n$poubelle\n${ttphoto[*]}\n" > $fichier_inf
    $1/out $fichier_inf
fi
