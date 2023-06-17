import { Component, OnInit } from '@angular/core';
import { HttpClient, HttpParams } from '@angular/common/http';
import { Observable } from 'rxjs';

interface ApiResponse {
  success: boolean;
  message: string;
}

@Component({
  selector: 'app-product-catalog',
  templateUrl: './product-catalog.component.html',
  styleUrls: ['./product-catalog.component.css']
})
export class ProductCatalogComponent implements OnInit {
  products: any[] = [];
  category: string = '';
  page: number = 1;
  count: number = 0;
  perPage: number = 4;
  pages: number = 0;
  currentPage: number = 1;

  constructor(private http: HttpClient) { }

  ngOnInit() {
    this.loadProducts();
  }

  loadProducts() {
    let params = new HttpParams();
    params = params.set('category', this.category);
    params = params.set('page', this.page.toString());

    this.getProducts(params).subscribe(response => {
      this.products = response.products;
      this.count = response.count;
      this.pages = Math.ceil(this.count / this.perPage);
    });
  }

  filterProducts() {
    this.page = 1;
    this.loadProducts();
  }

  changePage(page: number) {
    this.page = page; // Update the current page
    this.currentPage = page; // Update the active page in the UI
    this.loadProducts();
  }
  
  getProducts(params: HttpParams): Observable<any> {
    return this.http.get<any>('http://localhost/e-commerce%20store/backend/browseProducts.php', { params: params });
  }

  getPagesArray(): number[] {
    return Array.from({ length: Math.ceil(this.count / this.perPage) }, (_, i) => i + 1);
  }
  
  addToCart(product: any) {
    const url = 'http://localhost/e-commerce%20store/backend/addProductToCart.php';
    const data = { productName: product.NAME, productCategory: product.CATEGORY };

    this.http.post<ApiResponse>(url, data).subscribe(response => {
      if (response.success) {
        alert(response.message);
      } else {
        alert('Error: ' + response.message);
      }
    });
  }

}
