int StrCpy(char *src,char *des){
	if(!(src&&des))
		return 0;
	int i=0;
	while(src[i]){
		des[i]=src[i];
		i++;
	}
	des[i]='\0';
	return 1;
}

