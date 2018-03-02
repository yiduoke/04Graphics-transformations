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
  struct matrix * edges;
  struct matrix * transform;

  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);

  // if ( argc == 2 ){
  //   parse_file( argv[1], transform, edges, s );
  // }
  // else{
  //   parse_file( "stdin", transform, edges, s );
  // }

  add_edge(edges, 0, 20, 0, 15, 20, 0);
  transform = make_rotX(90);
  matrix_mult(transform, edges);
  display(s);
	save_extension(s, "trans.png");
  free_matrix( edges );
  free_matrix( transform );

  return 0;
}