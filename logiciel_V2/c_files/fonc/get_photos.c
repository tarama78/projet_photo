int get_p(t_p *p, char *name)
{
    int		i;

    i = -1;
    while (++i < p->nb_p)
	if (p->p[i].name == name)
	    return (i);
    return (-1);
}

void get_full_name(t_p *p, int id, char *full_name)
{
    strcpy(full_name, p->dossier_p);
    strcat(full_name, "/");
    strcat(full_name, p->p[id].name);
}

void get_new_name(t_p *p, int id, char *name)
{
    char	min_name[100];
    char	add_name[100];
    char	extention[100];
    int		i;
    int		j;

    i = -1;
    strcpy(min_name, p->p[id].name);
    while (min_name[++i] != '_');
    min_name[i + 1] = '\0';
    i = -1;
    strcpy(extention, p->p[id].name);
    while (p->p[id].name[++i] != '.');
    j = -1;
    extention[++j] = p->p[id].name[i];
    while (p->p[id].name[++i] != '\0')
	extention[++j] = p->p[id].name[i];
    extention[j + 1] = '\0';
    i = -1;
    j = -1;
    add_name[0] = ' ';
    while (++i < 26)
	if (p->p[id].letter[i] == 1)
	    add_name[++j] = i + 65;
    if (add_name[0] != ' ')
	add_name[++j] = '_';
    add_name[++j] = 'V';
    add_name[++j] = '\0';
    strcpy(name, min_name);
    strcat(name, add_name);
    strcat(name, extention);
}

void get_full_new_name(t_p *p, int id, char *full_name)
{
    char	new_name[100];

    get_new_name(p, id, new_name);
    strcpy(full_name, p->dossier_p);
    strcat(full_name, "/");
    strcat(full_name, new_name);
}

void get_full_name_del(t_p *p, int id, char *full_name)
{
    strcpy(full_name, p->dossier_poubelle);
    strcat(full_name, "/");
    strcat(full_name, p->p[id].name);
}
