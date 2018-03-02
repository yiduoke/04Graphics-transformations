#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"

int main(int argc, char **argv) {

  screen s;
  color c;
  struct matrix * edges;
  struct matrix * transform;
  struct matrix * temp;

  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);
  ident(transform);
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = MAX_COLOR;

  if ( argc == 2 ){
    parse_file( argv[1], transform, edges, s );
  }
  else{
    parse_file( "stdin", transform, edges, s );
  }

  display(s);
	save_extension(s, "trans.png");
  free_matrix( edges );
  free_matrix( transform );

  return 0;
}
