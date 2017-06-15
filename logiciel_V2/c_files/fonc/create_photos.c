void create_t_gest_p(t_p *p)
{
    char	line[100];
    int		i;
    int		j;
    int		line_act;

    line_act = -1;
    while (++line_act < p->nb_p)
    {
	line[0] = ' ';
	i = 0;
	while (line[i++] != '\n')
	{
	    line[i] = fgetc(p->fichier_inf);
	    if (line[i] == EOF)
		break;
	}
	line[i - 1] = '\0';
	str_nospace(line);
	strcpy(p->p[line_act].name, line);
	p->p[line_act].state = NO_CHANGE;
	j = strlen(p->p[line_act].name);
	while (p->p[line_act].name[--j] != '.');
	if (p->p[line_act].name[j - 1] == 'V')
	    p->p_act = line_act;
	p->p[line_act].view = 0;
	j = -1;
	while (++j < 26)
	    p->p[line_act].letter[j] = 0;
	j = -1;
	while (p->p[line_act].name[++j] != '_');
	if (p->p[line_act].name[j + 1] != '.' &&
	    p->p[line_act].name[j + 2] != '.')
	    while (p->p[line_act].name[++j] != '_')
		p->p[line_act].letter[p->p[line_act].name[j] - 65] = 1;
    }
}

void create_t_p(t_p *p)
{
    char	line[100];
    int		i;
    int		line_act;

    line_act = -1;
    while (++line_act < 3)
    {
	line[0] = fgetc(p->fichier_inf);
	i = 0;
	while (line[i++] != '\n')
	    line[i] = fgetc(p->fichier_inf);
	line[i - 1] = '\0';
	str_nospace(line);
	if (line_act == 0)
	{
	    p->nb_p = atoi(line);
	    p->p = malloc(sizeof(t_gest_p)*p->nb_p);
	}
	else if (line_act == 1)
	    strcpy(p->dossier_p, line);
	else if (line_act == 2)
	    strcpy(p->dossier_poubelle, line);
    }
    p->p_act = -1;
}

void create_p(t_p *p, char *path)
{
    int		i;

    strcpy(p->path_prog, path);
    i = strlen(p->path_prog);
    while (p->path_prog[--i] != '/');
    p->path_prog[i] = '\0';
    p->fichier_inf = fopen(path, "a+");
    create_t_p(p);
    create_t_gest_p(p);
    fclose(p->fichier_inf);
    next_p(p);
}
