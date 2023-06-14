<?php
// Enable CORS
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Methods: GET, POST, OPTIONS");
header("Access-Control-Allow-Headers: Content-Type");

$con = new mysqli("localhost", "root", "", "e-commerce");

if (!$con) {
    die('Could not connect: ' . mysqli_error($con));
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $data = json_decode(file_get_contents("php://input"), true); // Retrieve data from the request body

    $name = mysqli_real_escape_string($con, $data["productName"]);
    $category = mysqli_real_escape_string($con, $data["productCategory"]);

    $sql = "SELECT ID FROM PRODUCTS WHERE NAME = ? AND CATEGORY = ?";
    $stmt = $con->prepare($sql);
    $stmt->bind_param("ss", $name, $category);
    $stmt->execute();
    $result = $stmt->get_result();

    if (mysqli_num_rows($result) > 0) {
        $row = mysqli_fetch_assoc($result);
        $productId = $row["ID"];

        $insertSql = "INSERT INTO CART (PRODUCT_ID) VALUES ($productId)";

        if (mysqli_query($con, $insertSql)) {
            $response = array("success" => true, "message" => "Product added to cart successfully.");
        } else {
            $response = array("success" => false, "message" => "Error: " . mysqli_error($con));
        }
    } else {
        $response = array("success" => false, "message" => "Product not found.");
    }

    mysqli_close($con);
    header("Content-Type: application/json");
    echo json_encode($response);
    exit;
}
?>
