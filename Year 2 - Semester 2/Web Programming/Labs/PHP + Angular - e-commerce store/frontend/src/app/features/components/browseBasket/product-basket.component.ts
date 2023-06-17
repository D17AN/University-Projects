import { Component, OnInit } from '@angular/core';
import { HttpClient, HttpParams } from '@angular/common/http';
import { Observable } from 'rxjs';

interface ApiResponse {
    success: boolean;
    message: string;
}

@Component({
    selector: 'app-product-basket',
    templateUrl: './product-basket.component.html',
    styleUrls: ['./product-basket.component.css']
})
export class ProductBasketComponent implements OnInit {
    products: any[] = [];
    
    constructor(private http: HttpClient){ }

    ngOnInit() {
        this.loadProducts();
    }

    loadProducts(){
        let params = new HttpParams();
        this.getProducts(params).subscribe(response => {
            this.products = response;
            console.log(this.products);
        });
    }

    getProducts(params: HttpParams): Observable<any>{
        return this.http.get<any>('http://localhost/e-commerce%20store/backend/browseBasket.php', { params: params });
    }

    removeFromBasket(product: any) {
        const url = 'http://localhost/e-commerce%20store/backend/deleteProductFromCart.php';
        const data = { productName: product.NAME, productCategory: product.CATEGORY };
    
        this.http.post<ApiResponse>(url, data).subscribe(response => {
          if (response.success) {
            alert(response.message);
            // Reload the products in the basket
            this.loadProducts();
          } else {
            alert('Error: ' + response.message);
          }
        });
      }

    confirmRemoveFromBasket(product: any) {
        const confirmed = window.confirm('Are you sure you want to remove this product from the basket?');
      
        if (confirmed) {
          this.removeFromBasket(product);
        }
      }
}