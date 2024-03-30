import { Component } from '@angular/core';
import { Database, DatabaseReference, object, ref, set } from '@angular/fire/database';


@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})

export class HomePage {
  bano: boolean = false;
  comedor: boolean = false;
  cocina: boolean = false;
  cuarto: boolean = false;
  cuarto2: boolean = false;
  cuarto3: boolean = false;
  cuarto4: boolean = false;
  cuarto5: boolean = false;
  oficina: boolean = false;
  patio: boolean = false;
  sala: boolean = false;

  constructor(private database:Database) {

  }
  ngOnInit() {
    const routebano: DatabaseReference = ref(this.database, "/casa/bano");
    object(routebano).subscribe(attributes => {
      this.bano = attributes.snapshot.val();
    });
    const routecomedor: DatabaseReference = ref(this.database, "/casa/comedor");
    object(routecomedor).subscribe(attributes => {
      this.comedor = attributes.snapshot.val();
    });
    const routecocina: DatabaseReference = ref(this.database, "/casa/cocina");
    object(routecocina).subscribe(attributes => {
      this.cocina = attributes.snapshot.val();
    });
    const routecuarto: DatabaseReference = ref(this.database, "/casa/cuarto");
    object(routecuarto).subscribe(attributes => {
      this.cuarto = attributes.snapshot.val();
    });
    const routecuarto2: DatabaseReference = ref(this.database, "/casa/cuarto2");
    object(routecuarto2).subscribe(attributes => {
      this.cuarto2 = attributes.snapshot.val();
    });
    const routecuarto3: DatabaseReference = ref(this.database, "/casa/cuarto3");
    object(routecuarto3).subscribe(attributes => {
      this.cuarto3 = attributes.snapshot.val();
    });
    const routecuarto4: DatabaseReference = ref(this.database, "/casa/cuarto4");
    object(routecuarto4).subscribe(attributes => {
      this.cuarto4 = attributes.snapshot.val();
    });
    const routecuarto5: DatabaseReference = ref(this.database, "/casa/cuarto5");
    object(routecuarto5).subscribe(attributes => {
      this.cuarto5 = attributes.snapshot.val();
    });
    const routeoficina: DatabaseReference = ref(this.database, "/casa/oficina");
    object(routeoficina).subscribe(attributes => {
      this.oficina = attributes.snapshot.val();
    });
    const routepatio: DatabaseReference = ref(this.database, "/casa/patio");
    object(routepatio).subscribe(attributes => {
      this.patio = attributes.snapshot.val();
    });
    const routesala: DatabaseReference = ref(this.database, "/casa/sala");
    object(routesala).subscribe(attributes => {
      this.sala = attributes.snapshot.val();
    });
  }
  toggleLight(room: string, currentStatus: boolean) {
    const roomRef: DatabaseReference = ref(this.database, `/casa/${room}`);
    set(roomRef, !currentStatus);
  }
}