import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { ProductCatalogComponent } from './features/components/browseProducts/product-catalog.component'
import { ProductBasketComponent } from './features/components/browseBasket/product-basket.component';

const routes: Routes = [
  { path: 'browseProducts', component: ProductCatalogComponent },
  { path: 'browseBasket', component: ProductBasketComponent},
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
