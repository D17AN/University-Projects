<?php
// Enable CORS
header("Access-Control-Allow-Origin: *");
header("Access-Control-Allow-Methods: GET, POST, OPTIONS");
header("Access-Control-Allow-Headers: Content-Type");

$conn = new mysqli("localhost", "root", "", "e-commerce");

if (!$conn) {
    die('Could not connect: ' . mysqli_error($conn));
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $data = json_decode(file_get_contents("php://input"), true);

    $name = mysqli_real_escape_string($conn, $data["name"]);
    $category = mysqli_real_escape_string($conn, $data["category"]);
    $newPrice = mysqli_real_escape_string($conn, $data["newPrice"]);

    $sql = "UPDATE PRODUCTS SET PRICE = ? WHERE NAME = ? AND CATEGORY = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("dss", $newPrice, $name, $category);
    $stmt->execute();

    if ($stmt->affected_rows > 0) {
        $response = array("success" => true, "message" => "Product updated successfully.");
    } else {
        $response = array("success" => false, "message" => "Product not found.");
    }

    mysqli_close($conn);
    header("Content-Type: application/json");
    echo json_encode($response);
    exit;
}
?>