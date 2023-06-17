<?php
    // Enable CORS
    header("Access-Control-Allow-Origin: *");
    header("Access-Control-Allow-Methods: GET, POST, OPTIONS");
    header("Access-Control-Allow-Headers: Content-Type");
    // Database connection
    $conn = new mysqli("localhost", "root", "", "e-commerce");

    if(!$conn){
        die('Could not connect: ' .mysqli_error($conn));
    }

    // Get page
    // If page is not defined, it's the first page
    if(isset($_GET['page'])){
        $page = $_GET['page'];
    }
    else{
        $page = 1; // page initialized with 1
    }

    // Get the category filter
    if(isset($_GET['category'])){
        $category = $_GET['category'];
        $sql_query = "SELECT COUNT(*) as count FROM PRODUCTS WHERE CATEGORY = ?";
        $stmt = $conn->prepare($sql_query);
        $stmt->bind_param("s", $category);
    }
    else{
        $category = '';
        $sql_query = "SELECT COUNT(*) as count FROM PRODUCTS";
        $stmt = $conn->prepare($sql_query);
    }
    $stmt->execute();
    $result = $stmt->get_result();
    $count = $result->fetch_assoc()['count'];

    // Items per page
    $per_page = 4;
    $pages = ceil($count / $per_page);

    // Starting index for current page
    $start = ($page - 1) * $per_page;

    // Retrieve the count value again based on the modified query
    if($category){
        $sql_query_count = "SELECT COUNT(*) as count FROM PRODUCTS WHERE CATEGORY = ?";
        $stmt_count = $conn->prepare($sql_query_count);
        $stmt_count->bind_param("s", $category);
    }
    else{
        $sql_query_count = "SELECT COUNT(*) as count FROM PRODUCTS";
        $stmt_count = $conn->prepare($sql_query_count);
    }
    $stmt_count->execute();
    $result_count = $stmt_count->get_result();
    $count = $result_count->fetch_assoc()['count'];

    // Retrieve the products for the current page
    if($category){
        $sql_query_products = "SELECT * FROM PRODUCTS WHERE CATEGORY = ? LIMIT $start, $per_page";
        $stmt_products = $conn->prepare($sql_query_products);
        $stmt_products->bind_param("s", $category);
    }
    else{
        $sql_query_products = "SELECT * FROM PRODUCTS LIMIT $start, $per_page";
        $stmt_products = $conn->prepare($sql_query_products);
    }
    $stmt_products->execute();
    $result_products = $stmt_products->get_result();
    $products = $result_products->fetch_all(MYSQLI_ASSOC);

    // Create an array to hold the count and products
    $response = array(
        'count' => (int)$count,
        'products' => $products
    );

    // Close the connections
    $stmt->close();
    $stmt_count->close();
    $stmt_products->close();
    $conn->close();

    // Encode response array as JSON
    $json_response = json_encode($response);

    // Set the response headers
    header('Content-Type: application/json');
    header('Content-Length: ' . strlen($json_response));

    // Send the JSON response
    echo $json_response;
?>
