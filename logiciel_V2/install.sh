#!/bin/bash

touch photo
echo -e "#!/bin/bash

continuer='1'
chemin=\"`pwd`\"
\n
if [ \$# == \"1\" ]; then
	bash \$chemin/photo.sh \$chemin \$1
elif [ \$# == "2" ]; then
	bash \$chemin/photo.sh \$chemin \$1 \$2
else
	continuer='0'
	echo \"ERREUR : le nombre de parametre est incorrecte -> \$#\"
fi
" > photo

sudo cp photo /bin
sudo chmod 777 /bin/photo
