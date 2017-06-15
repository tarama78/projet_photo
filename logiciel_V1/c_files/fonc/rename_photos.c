void rename_photos_name(t_photos *photos, char *name, char *new_name)
{
    int		id;
    int		i;

    id = get_photos(photos, name);
    if (id == -1)
	printf("rename_photos : nom <%s> invalide", name);
    else
    {
	if (photos->photos[id].state == DELETE)
	    printf("*** rename_photos : impossible de renomer la photo \
		elle a ete supprimer ***\n");
	else
	{
	    i = -1;
	    while (++i < (int)strlen(name))
		photos->photos[id].new_name[i] = new_name[i];
	    photos->photos[id].state = NEW_NAME;
	}
    }
}

void rename_photos_id(t_photos *photos, int id, char *new_name)
{
    rename_photos_name(photos, photos->photos[id].name, new_name);
}
