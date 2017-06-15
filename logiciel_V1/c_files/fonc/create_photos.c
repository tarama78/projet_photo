void create_t_gest_photos(t_photos *photos)
{
    char	line[100];
    int		i;
    int		j;
    int		line_act;

    line_act = -1;
    while (++line_act < photos->nb_photos)
    {
	line[0] = ' ';
	i = 0;
	while (line[i++] != '\n')
	{
	    line[i] = fgetc(photos->fichier_inf);
	    if (line[i] == EOF)
		break;
	}
	line[i - 1] = '\0';
	str_nospace(line);
	strcpy(photos->photos[line_act].name, line);
	photos->photos[line_act].state = NO_CHANGE;
	j = -1;
	while (++j < 26)
	    photos->photos[line_act].letter[j] = 0;
	j = strlen(photos->photos[line_act].name);
	while (photos->photos[line_act].name[--j] != '.');
	if (photos->photos[line_act].name[j - 1] == 'V')
	    photos->photo_act = line_act;
	photos->photos[line_act].view = 0;
    }
}

void create_t_photos(t_photos *photos)
{
    char	line[100];
    int		i;
    int		line_act;

    line_act = -1;
    while (++line_act < 3)
    {
	line[0] = fgetc(photos->fichier_inf);
	i = 0;
	while (line[i++] != '\n')
	    line[i] = fgetc(photos->fichier_inf);
	line[i - 1] = '\0';
	str_nospace(line);
	if (line_act == 0)
	{
	    photos->nb_photos = atoi(line);
	    photos->photos = malloc(sizeof(t_gest_photo)*photos->nb_photos);
	}
	else if (line_act == 1)
	    strcpy(photos->dossier_photos, line);
	else if (line_act == 2)
	    strcpy(photos->dossier_poubelle, line);
    }
    photos->photo_act = -1;
}

void create_photos(t_photos *photos, char *path)
{
    int		i;

    strcpy(photos->path_prog, path);
    i = strlen(photos->path_prog);
    while (photos->path_prog[--i] != '/');
    photos->path_prog[i] = '\0';
    photos->fichier_inf = fopen(path, "r");
    create_t_photos(photos);
    create_t_gest_photos(photos);
    next_photos(photos);
    fclose(photos->fichier_inf);
}
