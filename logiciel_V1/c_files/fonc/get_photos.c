int get_photos(t_photos *photos, char *name)
{
    int		i;

    i = -1;
    while (++i < photos->nb_photos)
	if (photos->photos[i].name == name)
	    return (i);
    return (-1);
}

void get_full_name(t_photos *photos, int id, char *full_name)
{
    strcpy(full_name, photos->dossier_photos);
    strcat(full_name, "/");
    strcat(full_name, photos->photos[id].name);
}

void get_full_new_name(t_photos *photos, int id, char *full_name)
{
    char	min_name[100];
    char	add_name[100];
    char	extention[100];
    char	new_name[100];
    int		i;
    int		j;

    (void)add_name;
    i = -1;
    strcpy(min_name, photos->photos[id].name);
    while (min_name[++i] != '_');
    min_name[i + 1] = '\0';
    i = -1;
    strcpy(extention, photos->photos[id].name);
    while (photos->photos[id].name[++i] != '.');
    j = -1;
    extention[++j] = photos->photos[id].name[i];
    while (photos->photos[id].name[++i] != '\0')
	extention[++j] = photos->photos[id].name[i];
    extention[j + 1] = '\0';
    i = -1;
    j = -1;
    add_name[0] = ' ';
    while (++i < 26)
    {
	if (photos->photos[id].letter[i] == 1)
	    add_name[++j] = i + 65;
    }
    if (add_name[0] != ' ')
	add_name[++j] = '_';
    add_name[++j] = 'V';
    add_name[++j] = '\0';
    strcpy(new_name, min_name);
    strcat(new_name, add_name);
    strcat(new_name, extention);
    strcpy(full_name, photos->dossier_photos);
    strcat(full_name, "/");
    strcat(full_name, new_name);
}

void get_full_name_del(t_photos *photos, int id, char *full_name)
{
    strcpy(full_name, photos->dossier_poubelle);
    strcat(full_name, "/");
    strcat(full_name, photos->photos[id].name);
}
