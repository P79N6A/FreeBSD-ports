http://www.squid-cache.org/Versions/v3/3.5/changesets/SQUID-2018_1.patch

commit eb2db98a676321b814fc4a51c4fb7928a8bb45d9 (refs/remotes/origin/v3.5)
Author: Amos Jeffries <yadij@users.noreply.github.com>
Date:   2018-01-19 13:54:14 +1300

    ESI: make sure endofName never exceeds tagEnd (#130)

--- src/esi/CustomParser.cc.orig	2018-02-23 13:37:52 UTC
+++ src/esi/CustomParser.cc
@@ -121,7 +121,7 @@ ESICustomParser::parse(char const *dataToParse, size_t
 
             char * endofName = strpbrk(const_cast<char *>(tag), w_space);
 
-            if (endofName > tagEnd)
+            if (!endofName || endofName > tagEnd)
                 endofName = const_cast<char *>(tagEnd);
 
             *endofName = '\0';
@@ -214,7 +214,7 @@ ESICustomParser::parse(char const *dataToParse, size_t
 
             char * endofName = strpbrk(const_cast<char *>(tag), w_space);
 
-            if (endofName > tagEnd)
+            if (!endofName || endofName > tagEnd)
                 endofName = const_cast<char *>(tagEnd);
 
             *endofName = '\0';