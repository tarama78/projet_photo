void del_photos_id(t_photos *photos, int id)
{
    photos->photos[id].state = DELETE;
}

void del_photos_name(t_photos *photos, char *name)
{
    int		i;

    i = -1;
    while (++i < photos->nb_photos)
    {
	if (photos->photos[i].name == name)
	    break;
    }
    del_photos_id(photos, i);
}
