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

  // add_edge(edges, 100,100,0,100,400,0);
  // add_edge(edges, 100,400,0,400,400,0);
  // add_edge(edges, 400,400,0,400,100,0);
  // add_edge(edges, 400,100,0,100,100,0);
  // matrix_mult(make_scale(1.5, 1.5, 1.5), transform);
  // matrix_mult(transform, edges);
  // draw_lines(edges, s, c);

  display(s);
	save_extension(s, "trans.png");
  free_matrix( edges );
  free_matrix( transform );

  return 0;
}
