import { Product } from "./product";

export interface cartProduct{
    id: number;
    product_id: Product | number;
}