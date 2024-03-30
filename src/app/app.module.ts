import { EnvironmentInjector, NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { RouteReuseStrategy } from '@angular/router';
import { initializeApp, provideFirebaseApp } from '@angular/fire/app';
import { getDatabase, provideDatabase} from '@angular/fire/database';
import { environment } from '../environments/environment';

import { IonicModule, IonicRouteStrategy } from '@ionic/angular';

import { AppComponent } from './app.component';
import { AppRoutingModule } from './app-routing.module';

@NgModule({
  declarations: [AppComponent],
  imports: [BrowserModule, IonicModule.forRoot(), AppRoutingModule,
    provideFirebaseApp(() => initializeApp(environment.firebase)),
    provideDatabase(() => getDatabase()),
    provideFirebaseApp(() => initializeApp({"projectId":"rtdb-expl-8cffc","appId":"1:867479733134:web:2d3b6c9c4298345b6a1adf","databaseURL":"https://rtdb-expl-8cffc-default-rtdb.firebaseio.com","storageBucket":"rtdb-expl-8cffc.appspot.com","apiKey":"AIzaSyDqQd7DgXjISmqdwXQ7SThZ1kB520W0-Es","authDomain":"rtdb-expl-8cffc.firebaseapp.com","messagingSenderId":"867479733134"}))],
  providers: [{ provide: RouteReuseStrategy, useClass: IonicRouteStrategy }],
  bootstrap: [AppComponent],
})
export class AppModule {}
