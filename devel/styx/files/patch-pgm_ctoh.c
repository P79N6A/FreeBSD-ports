--- pgm/ctoh.c.orig	2002-12-02 12:45:37 UTC
+++ pgm/ctoh.c
@@ -135,7 +135,7 @@ void patchhead(void)
   }
 }
 
-bool getline(void)
+bool get_line(void)
 {
   if( scan_line != NULL ) FreeMem(scan_line);
   if ((scan_line = Line_get(SysIn)) == NULL)
@@ -630,7 +630,7 @@ void copyBlock(bool skipFirst, bool DocB
     {
       t = convBlock(temp); FreeMem(temp); temp = t;
     }
-    if( getline() && CTypConv )
+    if( get_line() && CTypConv )
     {
       t = convBlock(line); FreeMem(line); scan_line = line = t;
     }
@@ -657,7 +657,7 @@ void copyBlock(bool skipFirst, bool DocB
       line[rgh+1] = 0;
       pushFuncLine(temp,StrCopy(line+lft));
     }
-    while( line[0] != 0 && line[0] != '{') getline();
+    while( line[0] != 0 && line[0] != '{') get_line();
     return;
 Ordinary:
     if( GenExp && line[0] != 0 )
@@ -703,7 +703,7 @@ Ordinary:
       ext = Sink_open();
     Sink_printf(ext,"%s\n",line);
   }
-  while(getline() && line[0] != 0 && line[0] != '{' )
+  while(get_line() && line[0] != 0 && line[0] != '{' )
   {
     if( extflg &=
         ( !beginswith("/*") && !beginswith("//") && !beginswith("#") ))
@@ -765,7 +765,7 @@ Ordinary:
 
 void skipDoc(void)
 {
-  while(getline() && strcmp(line,"#endif") != 0) /* skip */;
+  while(get_line() && strcmp(line,"#endif") != 0) /* skip */;
 }
 
 void copyDoc
@@ -808,7 +808,7 @@ void copyDoc
   }
   if( t2 == (string)NULL)
   {
-    while(getline() )
+    while(get_line() )
     {
       fprintf(SysOut,"%s\n",line);
       if( (t2=strstr(line,szEndTag)) != (string)NULL)
@@ -850,7 +850,7 @@ void copyToI(string szEndTag, bool force
   if( CTypConv ) pSnk = Sink_open();
   if( forcedDocBlock )
     fprintf(SysDoc,"<br><pre>\n");
-  while(getline() && strcmp(line,szEndTag) != 0)
+  while(get_line() && strcmp(line,szEndTag) != 0)
   {
     if( CTypConv ) Sink_printf(pSnk,"%s\n",line);
     else           
@@ -900,7 +900,7 @@ void convertText(void)
   Shift       = False;
   OnOff       = True; /* INTERFACE_ON ! */
   mainSeen    = False;
-  if (getline()) copyBlock(False,False,False);
+  if (get_line()) copyBlock(False,False,False);
   if (!Patched) fprintf(STDERR,"Warning: %s missing header comment.\n",cfid);
   Patched = True;
   fprintf(SysOut,"/* File generated by 'ctoh'. Don't change manually. */\n");
@@ -924,7 +924,7 @@ void convertText(void)
     fprintf(SysOut,"#endif\n");
     fprintf(SysOut,"\n");
   }
-  while (getline())
+  while (get_line())
   {
     if( CLinkageFlag == False && IncludeSeen == True )
     {