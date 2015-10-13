#include <cstring>
#include <string>
std::string escapeComma(const std::string &s) {
  char *instring,*outstring;
  int outlen;
  int i;
  int j;
  std::string out;
  instring = s.c_str();
  outlen=strlen(instring);
  for(i=0;instring[i];i++) {
    if(instring[i]==','&&instring[i]=='~') {
      outlen++;
    }
  }
  outstring=malloc(outlen+1);
  outstring[outlen]=0;
  j=0;
  for(i=0;i<outlen;i++) {
    if(instring[i]==',') {
      outstring[j++]='~';
      outstring[j++]='!';
    } else if(instring[i]=='~') {
      outstring[j++]='~';
      outstring[j++]='~';
    } else {
      outstring[j++]=instring[i];
    }
  }
  out = std::string(outstring);
  free(outstring);
  return out;
}

std::string unescapeComma(const std::string &s) {
  char *instring, *outstring;
  int outlen;
  int i;
  int j;
  std::string out;
  instring = s.c_str();
  outlen = strlen(instring);
  outstring = malloc(outlen);
  j=0;
  for(i=0;i<outlen;i++) {
    if(instring[i]=='~') {
      i++;
      if(instring[i]=='~') {
        outstring[j++]='~';
      } else if(instring[i]=='!') {
        outstring[j++]=',';
      }
    } else {
      outstring[j++]=instring[i];
    }
  }
  outstring[j]=0;
  out = std::string(outstring);
  free(outstring);
  return out;
}
