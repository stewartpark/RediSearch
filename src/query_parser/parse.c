#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "parse.h"

/* forward declarations of stuff generated by lemon */
void Parse(void *yyp, int yymajor, QueryToken yyminor, parseCtx *ctx);
void *ParseAlloc(void *(*mallocProc)(size_t));
void ParseFree(void *p, void (*freeProc)(void *));

QueryStage *Query_Parse(Query *q, char **err) {
  void *pParser = ParseAlloc(malloc);
  int t = 0;

  QueryToken tok;
  QueryTokenizer qt = NewQueryTokenizer(q->raw, q->len, q->stopwords);
  parseCtx ctx = {.root = NULL, .ok = 1, .errorMsg = NULL, .q = q};

  while ((t = QueryTokenizer_Next(&qt, &tok)) && ctx.ok) {
    //printf("tok %d, string %.*s\n", t, tok.len, tok.s);
    Parse(pParser, t, tok, &ctx);
  }

  if (ctx.ok) {
    Parse(pParser, 0, tok, &ctx);
  }
  ParseFree(pParser, free);
  if (err) {
    *err = ctx.errorMsg;
  }
  
  if (ctx.root) {
    QueryStage_AddChild(q->root, ctx.root);
  }
  return ctx.root;
}
