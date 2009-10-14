#include <string.h>
#include <stdio.h>

#include <npapi.h>
#include <npruntime.h>


/* Define global variable to hold the user agent string. */
static char* userAgent = NULL;
 
/* Initialize function. */
NPError NP_Initialize(void)
{
  /* Get the user agent from the browser. */
  char* result = NPN_UserAgent(NULL);
  if (result == NULL) return NPERR_OUT_OF_MEMORY_ERROR;

  /* Allocate some memory so that you can keep a copy of it. */
  userAgent = (char*) NPN_MemAlloc(strlen(result) + 1);
  if (userAgent == NULL) return NPERR_OUT_OF_MEMORY_ERROR;

  /* Copy the string to your memory. */
  strcpy(userAgent, result);

  return NPERR_NO_ERROR;
}
 
/* Shutdown function */
NPError NP_Shutdown(void)
{
  /* Delete the memory you allocated. */
  if (userAgent != NULL)
    NPN_MemFree(userAgent);

  return NPERR_NO_ERROR;
}
