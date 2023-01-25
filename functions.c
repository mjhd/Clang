double mean(char* strng, char* town) {
	while(strng)
	{
		int hit = 0;
		int matchcount = 0;
		int master_it = 12;
		while(strng && *strng != ':')
		{
			while(*strng && strng[matchcount] == town[matchcount])
			{
				if(strng[++matchcount] == ':')
				{
					hit = 1;
					double value = 0.0;
					int itrcnt = 0;

					while(strng && *strng != '\n')
					{
          
						if((*strng <= 57 && *strng >= 48) || *strng == '-')
						{
							double current = 0.0;
							while(*strng != '.')
							{
								current *= 10;
								current += ((*strng++) - '0');
							}
							itrcnt += (*strng == '.') ? 1 : 0;
							while(*++strng != ',' && *strng != '\n')
							{
								current *= 10;
								current += ((double)((*strng) - '0'));
								current *= 0.1;
							}
							value += current;
						}
						else
							strng++;
					}
					value = (!hit) ? -1 : value / itrcnt;
          if(!(itrcnt == 12))
            return(-1);
          if(!value)
            return(-1);
					return(value);
				}
			}
			strng++;
			master_it -= (*strng == ':') ? 1 : 0;
			if(!(*strng))
				break;
		}
		if(!(*strng))
			break;
		strng++;
	}
  return 0;
}




double variance(char* strng, char* town)
{
	while(strng)
	{
		int hit = 0;
		int matchcount = 0;

		while(strng && *strng != ':')
		{
			while(*strng && strng[matchcount] == town[matchcount])
			{
				if(strng[++matchcount] == ':')
				{
					hit = 1;
					double sample_mean = mean(strng, town);
					double variance_value = 0.0;

					while(strng && *strng != '\n')
					{
						if((*strng <= 57 && *strng >= 48) || *strng == '-')
						{
							double current = 0.0;
							while(*strng != '.')
							{
								current *= 10;
								current += ((*strng++) - '0');
							}
							while(*++strng != ',' && *strng != '\n')
							{
								current *= 10;
								current += ((double)((*strng) - '0'));
								current *= 0.1;
							}
							variance_value += ((current - sample_mean) * (current - sample_mean));
						}
						else
							strng++;
					}
					return((!hit) ? -1 : variance_value / 12);
				}
			}
			strng++;
			if(!(*strng))
				break;
		}
		if(!(*strng))
			break;
		strng++;
	}
}