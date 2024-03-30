import { Component } from '@angular/core';
import { Database, object, ref } from '@angular/fire/database';


@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})

export class HomePage {

  constructor(private database:Database) {
  
  }
  ngOnInit() {
    const route = ref(this.database, 'https://rtdb-expl-8cffc-default-rtdb.firebaseio.com/');
    object(route).subscribe(attributes => {
      const valores_db = attributes.snapshot.val();
      console.log('sala');//Imprimir valores obtenidos de la busqueda en la ruta 
    });
  }
}